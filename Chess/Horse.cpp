#include "Horse.h"
Horse::Horse(char col, int row, bool team) : Piece::Piece(col, row, team, "assets/horse.png")
{
	value = 7;
}

std::vector<Rectangle> Horse::calculate_range(std::vector<Piece*> pieces)
{
	int col_mult = 2;
	int row_mult = 1;
	if (is_selected == true)
	{
		//All positions
		for (int p = 0; p < 2; p++)
		{
			for (int j = 1; j > -2; j -= 2)
			{
				for (int i = 1; i > -2; i -= 2)
				{
					range_quad.x = float(((col + (j * col_mult)) % 65) * 128 + 14);
					range_quad.y = float((row + (i * row_mult)) * 128 + 14);

					if (check_collision(range_quad, pieces))
					{
						continue;
					}

					range_quads.push_back(range_quad);
				}
			}
			col_mult = 1;
			row_mult = 2;
		}

	}
	else
	{
		if (range_quads.empty() == false)
			range_quads.clear();
	}
	return range_quads;
}
