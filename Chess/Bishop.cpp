#include "Bishop.h"

Bishop::Bishop(char col, int row, bool team): Piece::Piece(col, row, team, "assets/bishop.png")
{
	value = 10;
}

Bishop::~Bishop()
{
}

std::vector<Rectangle> Bishop::calculate_range(std::vector<Piece*> pieces)
{
	bool time_break = false;
	bool lef_end = false;
	if (is_selected == true)
	{
		for (int j = -1; j < 2; j+=2)
		{
			for (int i = 0; i < range; i++)
			{
				range_quad.x = (float)((col % 65) * 128 + (j* 128 * (i + 1)) + 14);
				range_quad.y = (float)((row + 1) * 128 * (i + 1) + 14);

				if (range_quad.x < 0 || range_quad.x > 1280)
					break;

				for (auto p : pieces)
				{
					if (p->get_team() == is_white)
					{
						if (CheckCollisionRecs(range_quad, p->get_hit_box()) == true)
						{
							time_break = true;
							break;
						}
					}
				}
				if (time_break)
				{
					time_break = false;
					break;
				}
				range_quads.push_back(range_quad);
			}
		}
	}
	else
	{
		if (range_quads.empty() == false)
			range_quads.clear();
	}

	for (Rectangle& r : range_quads)
	{
		DrawRectangleRec(r, fade_green);
	}
	return range_quads;
}

void Bishop::move(char col, int row, std::vector<Piece*>& pi)
{
	this->col = col;
	this->row = row;
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
