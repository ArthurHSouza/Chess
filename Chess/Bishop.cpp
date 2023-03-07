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
		for (int j = 1; j > -2; j -= 2)
		{
			for (int i = 0; i < max_range; i++)
			{
				range_quad.x = float(((col + 1) % 65) * 128 + (128 * i) + 14);
				range_quad.y = float((row + (j*1)) * 128 +( j *(128 * i)) + 14);

				for (const auto p : pieces)
				{
					//Da pra simplificar colocando essa verificao dentro da verificacao de colision
					if (is_white != p->get_team())
					{
						if (CheckCollisionRecs(range_quad, p->get_hit_box()))
						{
							time_break = true;
							range_quads.push_back(range_quad);
							break;
						}
					}
					else
					{
						if (CheckCollisionRecs(range_quad, p->get_hit_box()))
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
	std::cout << range_quads.size();
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
