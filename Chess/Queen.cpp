#include "Queen.h"

Queen::Queen(char col, int row, bool team): Piece::Piece(col, row, team, "assets/queen.png")
{
	value = 9;
}

std::vector<Rectangle> Queen::calculate_range(std::vector<Piece*> pieces)
{
	if (is_selected == true)
	{
		for (int j = 1; j > -2; j -= 2)
		{
			for (int i = 0; i < max_range; i++)
			{
				range_quad.x = float(((col + (j * 1) * (i + 1)) % 65) * 128 + 14);
				range_quad.y = float(row * 128 + 14);

				if (check_collision(range_quad, pieces))
				{
					break;
				}

				range_quads.push_back(range_quad);

			}
			for (int i = 0; i < max_range; i++)
			{
				range_quad.x = float((col % 65) * 128 + 14);
				range_quad.y = float((row + j * (i + 1)) * 128 + 14);

				if (check_collision(range_quad, pieces))
				{
					break;
				}

				range_quads.push_back(range_quad);
				std::cout << range_quad.x << std::endl;


			}

			//Bishop part
			//Right
			for (int i = 0; i < max_range; i++)
			{
				range_quad.x = float(((col + 1) % 65) * 128 + (128 * i) + 14);
				range_quad.y = float((row + (j * 1)) * 128 + (j * (128 * i)) + 14);


				if (check_collision(range_quad, pieces))
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