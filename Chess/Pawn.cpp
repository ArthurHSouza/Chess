#include "Pawn.h"
#include "Queen.h"

Pawn::Pawn(char col, int row, bool team) : Piece::Piece(col, row, team,"assets/pawn.png")
{
	value = 1;
	max_range = 2;
}

Pawn::~Pawn()
{
}

std::vector < Rectangle> Pawn::calculate_range(std::vector<Piece*> pieces)
{
	time_break = false;

	if (is_selected == true)
	{
		if (first_time_moving == false)
			max_range = 1;

		//Convertendo a coluna para um valor numérico
		range_quad.x = (float)( (col%'A') * 128 + 14);
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
						attack_rec_right.y = (float)((row - 1) * 128 + 14);
						attack_rec_left.y = attack_rec_right.y;//(float)((row - 1) * 128 + 14);
					}
					else
					{
						attack_rec_right.y = (float)((row + 1) * 128 + 14);
						attack_rec_left.y = attack_rec_right.y;// (float)((row + 1) * 128 + 14);
					}

					attack_rec_right.x = (float)((col % 'A') * 128 + 128 + 14);
					attack_rec_left.x = (float)((col % 'A') * 128 - 128 + 14);

					//Verify if attack_rec_right or attack_rec_left are overlapping a enemy piece
					if (CheckCollisionRecs(attack_rec_right, p->get_hit_box()))
					{
						range_quads.push_back(attack_rec_right);
					}
					if (CheckCollisionRecs(attack_rec_left, p->get_hit_box()))
					{
						range_quads.push_back(attack_rec_left);
					}
				
				}
				//The range was blocked by a piece of the same team
				if (CheckCollisionRecs(range_quad, p->get_hit_box()))
				{
					time_break = true;
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

void Pawn::move(char input_col, int input_row, std::vector<Piece*>& pieces)
{
	Piece::move(input_col, input_row, pieces);
	first_time_moving = false;
	become_queen(pieces);
}

void Pawn::become_queen(std::vector<Piece*>& pieces)
{
	for (int i = 0; i < pieces.size(); i++)
	{
		if (row == 0 || row == 7)
		{
			if (CheckCollisionRecs(pieces.at(i)->get_hit_box(), hitbox))
			{
				inner_queen = new Queen(col, row, is_white);
				pieces.erase(pieces.begin() + i);
				pieces.push_back(inner_queen);
				delete this;
				return;
			}
		}
	}
}