#include "Pawn.h"
#include "Board.h"


Pawn::Pawn(char col, int row, bool team):
	Piece::Piece(col, row, team,"assets/pawn.png")
{
	value = 5;
	max_range = 2;
}

Pawn::~Pawn()
{
}

std::vector < Rectangle> Pawn::calculate_range(std::vector<Piece*> pieces)//team_pieces, std::vector<Piece*> enemy_pieces)
{
	time_break = false;

	if (is_selected == true)
	{
		if (first_time_moving == false)
			max_range = 1;

		range_quad.x = (float)( (col%65) *128 +14); //Convertendo a coluna para um valor numérico
		for (int i = 0; i < max_range; i++)
		{
			if (is_white == true)
			{
				range_quad.y = (float)(128 * (row - i - 1) + 14);
			}
			else
				range_quad.y = (float)(128 * (row + i + 1) + 14);

			for (const auto p : pieces)
			{
				if (p->get_team() != is_white)
				{
					if (is_white == true)
					{
						attack_rec_right.y = (row - 1) * 128 + 14;
						attack_rec_left.y = (row - 1) * 128 + 14;
					}
					else
					{
						attack_rec_right.y = (row + 1) * 128 + 14;
						attack_rec_left.y = (row + 1) * 128 + 14;
					}

					attack_rec_right.x = (col % 65) * 128 + 128 + 14;
					attack_rec_left.x = (col % 65) * 128 - 128 + 14;

					if (CheckCollisionRecs(attack_rec_right, p->get_hit_box()) == true)
					{
						range_quads.push_back(attack_rec_right);
					}
					if (CheckCollisionRecs(attack_rec_left, p->get_hit_box()) == true)
					{
						range_quads.push_back(attack_rec_left);
					}
				
				}
				if (CheckCollisionRecs(range_quad, p->get_hit_box()) == true)
				{
					time_break = true;
					//break;
				}
			}
		if (time_break)
			break;
		range_quads.push_back(range_quad);
		}
	}
	else
	{
		if(range_quads.empty() == false)
			range_quads.clear();
	}

	return range_quads;
}

void Pawn::move(char input_col, int input_row, std::vector<Piece*>& pi)
{
	col = input_col;
	row = input_row;
	first_time_moving = false;

	range_quads.clear();

	char* o_col = new char;
	int o_row = 0;

	for (int i = 0; i < pi.size(); i++)
	{
		o_row = pi.at(i)->get_pos_col(o_col);
		if (pi.at(i)->get_team() != is_white)
		{
			if (col == *(o_col) && row == o_row)
			{
				delete pi.at(i);
				pi.erase(pi.begin() + i);
			}
		}
	}
	delete o_col;

}
