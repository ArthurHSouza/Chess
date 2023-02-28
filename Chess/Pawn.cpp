#include "Pawn.h"
#include "Board.h"


Pawn::Pawn(char col, int row, bool team):
	Piece::Piece(col, row, team,"assets/pawn.png")
{
	value = 1;
}

Pawn::~Pawn()
{

}

std::vector < Rectangle> Pawn::selected(std::vector<Piece*> pieces)
{
	time_break = false;

	if (is_selected == true)
	{
		if (first_time_moving == false)
			range = 1;

		range_quad.x = (float)( (col%65) *128 +14);
		for (int i = 0; i < range; i++)
		{
			range_quad.y = (float)(128 * (row + i + 1) + 14);

			for (auto p : pieces)
			{
				if (p->get_team() != is_white)
				{

					attack_rec_right.x = (col % 65) * 128 + 128 + 14;
					attack_rec_right.y = (row + 1) * 128 + 14;
					attack_rec_left.x = (col % 65) * 128 - 128 + 14;
					attack_rec_left.y = (row + 1) * 128 + 14;

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
					break;
				}
			}
		if (time_break)
			break;
		range_quads.push_back(range_quad);
		}
		
		for (Rectangle& r : range_quads)
		{
			DrawRectangleRec(r, fade_green);
		}
	}
	else
	{
		if(range_quads.empty() == false)
			range_quads.clear();
	}
	return range_quads;
}

void Pawn::move(char col, int row, std::vector<Piece*>& pi)
{
	this->col = col;
	this->row = row;
	first_time_moving = false;
	range_quads.clear();

	char* o_col = new char;
	int o_row = 0;

	for (int i = 0; i < pi.size(); i++)
	{
		o_row = pi.at(i)->get_pos_col(o_col);
		if (pi.at(i)->get_team() != is_white)
		{
			if (this->col == *(o_col) && this->row == o_row)
			{
				delete pi.at(i);
				pi.erase(pi.begin() + i);
			}
		}
	}
	delete o_col;

}
