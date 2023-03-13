#include "Tower.h"

Tower::Tower(char col, int row, bool team) : Piece::Piece(col, row, team, "assets/tower.png")
{
	value = 5;
}

std::vector<Rectangle> Tower::calculate_range(std::vector<Piece*> pieces)
{
	if (is_selected == true)
	{
		//The vairation of j is to get the up/down and left/right ranges
		for (int j = 1; j > -2; j -= 2)
		{
			//X range
			for (int i = 0; i < max_range; i++)
			{
				range_quad.x = float(((col + (j*1) * ( i + 1)) % 65) * 128 + 14);
				range_quad.y = float(row * 128 + 14);
				
				if (check_collision(range_quad, pieces))
				{
					break;
				}
				
				range_quads.push_back(range_quad);
			}
			//Y range
			for (int i = 0; i < max_range; i++)
			{
				range_quad.x = float((col % 65) * 128 + 14);
				range_quad.y = float((row + j * (i + 1)) * 128 + 14);

				if (check_collision(range_quad, pieces))
				{
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
	return range_quads;
}