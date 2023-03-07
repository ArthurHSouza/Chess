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
	if (is_selected == true)
	{
		for (int j = 1; j > -2; j -= 2)
		{
			//Right
			for (int i = 0; i < max_range; i++) 
			{
				range_quad.x = float(((col + 1) % 65) * 128 + (128 * i) + 14);
				range_quad.y = float((row + (j*1)) * 128 +( j *(128 * i)) + 14);
				/*
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
				*/
				
				if (check_collision(range_quad,pieces))
				{
					break;
				}
				
				range_quads.push_back(range_quad);
			}

			//left
			for (int i = 0; i < max_range; i++)
			{
				range_quad_left.x = float(((col - 1) % 65) * 128 + (128 * -i) + 14);
				range_quad_left.y = float((row - (j * 1)) * 128 + (j * (128 * -i)) + 14);
				if (check_collision(range_quad_left, pieces))
				{
					break;
				}

				range_quads.push_back(range_quad_left);
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