#include "Piece.h"
#include "King.h"

Piece::Piece(char col, int row, bool team, std::string path) :	col{ col }, row{ row }, is_white{team}, path_image{path}
{
	if (is_white == false)
	{
		piece_color = BLACK;
	}
	else
	{
		piece_color = LIGHTGRAY;
	}
	faded_green = Fade(GREEN, 0.5f);
	pieceImage = LoadTexture(path_image.c_str());
	
	hitbox.x = (float)((col % 'A') * 128);
	hitbox.y = (float)(row * 128);
}

Piece::~Piece()
{
	UnloadTexture(pieceImage);
}

void Piece::draw() const
{
	DrawTexture(pieceImage, (int)hitbox.x, (int)hitbox.y, piece_color);
}

void Piece::draw_range() const
{
	if(is_selected == true)
		for (Rectangle r : range_quads)
		{
			DrawRectangleRec(r, faded_green);
		}
}

int Piece::get_pos_col(char* col) const
{
	*col = this->col;
	return row;
}

void Piece::move(char input_col, int input_row, std::vector<Piece*>& pieces)
{
	col = input_col;
	row = input_row;
	
	char* o_col = new char;
	int o_row = 0;

	hitbox.x = (float)((col % 'A') * 128);
	hitbox.y = (float)(row * 128);


	for (int i = 0; i < pieces.size(); i++)
	{
		o_row = pieces.at(i)->get_pos_col(o_col);
		if (pieces.at(i)->get_team() != is_white)
		{
			//if (this->col == *(o_col) && this->row == o_row)
			if(CheckCollisionRecs(pieces.at(i)->get_hit_box(), hitbox))
			{
				delete pieces.at(i);
				pieces.erase(pieces.begin() + i);
			}
		}
	}

	range_quads.clear();
	delete o_col;
}

std::vector<Rectangle> Piece::calculate_range(std ::vector<Piece*> pieces)
{
	if (is_selected == true)
	{
		//The vairation of j is to get the up/down and left/right ranges
		for (int j = 1; j > -2; j -= 2)
		{
			//This first part it's to move like a tower
			//X range
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
			//This second part it's to move like a bishop
			//Calculate the right side of the range
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

			//Calculate the left side of the range
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

Rectangle Piece::get_hit_box() const
{
	return hitbox;
}

bool Piece::get_team() const
{
	return is_white;
}

bool Piece::get_is_selected() const
{
	return is_selected;
}

bool Piece::check_collision(Rectangle quad, std::vector<Piece*> pieces)
{
	time_break = false;
	for (auto p : pieces)
	{

		if (CheckCollisionRecs(quad, p->get_hit_box()))
		{
			time_break = true;

			if (is_white != p->get_team())
			{
				range_quads.push_back(quad);
			}
			break;
		}

	}

	return time_break;
}

void Piece::set_selected()
{
	is_selected = !is_selected;
}

void Piece::set_selected(bool val)
{
	if (val == false)
		range_quads.clear();
	is_selected = val;
}

void Piece::clear_range_quads()
{
	range_quads.clear();
}

int Piece::get_piece_value() const
{
	return value;
}
