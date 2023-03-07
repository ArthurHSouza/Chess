#include "Piece.h"

Piece::Piece(char col, int row, bool team, std::string path) :
	col{ col }, row{ row }, is_white{team}, path_image{path}
{
	fade_green = Fade(GREEN, 0.5f);
	pieceImage = LoadTexture(path_image.c_str());
}

Piece::~Piece()
{
	UnloadTexture(pieceImage);
}

void Piece::draw()
{
	for (int i = 'A'; i <= 'H'; i++)
	{
		if (i == col)
			hitbox.x = (float)(128 * (i - 'A'));
	}
	for (int i = 0; i < 8; i++)
	{
		if (i == row)
			hitbox.y = (float)(128 * i);
	}
	if (is_white == false)
		DrawTexture(pieceImage, (int)hitbox.x, (int)hitbox.y, BLACK);
	else
		DrawTexture(pieceImage, (int)hitbox.x, (int)hitbox.y, LIGHTGRAY);
}

void Piece::draw_range() const
{
	if(is_selected == true)
		for (Rectangle r : range_quads)
		{
			DrawRectangleRec(r, fade_green);
		}
}

int Piece::get_pos_col(char* col) const
{
	*col = this->col;
	return row;
}

void Piece::move(char col, int row, std::vector<Piece*>& pi)
{
	return;
}

std::vector<Rectangle> Piece::calculate_range(std ::vector<Piece*> pieces)
{
	std::vector<Rectangle>rec;
	return rec;
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
	for (const auto p : pieces)
	{
		//Da pra simplificar colocando essa verificao dentro da verificacao de colision
		if (is_white != p->get_team())
		{
			if (CheckCollisionRecs(quad, p->get_hit_box()))
			{
				time_break = true;
				range_quads.push_back(quad);
				break;
			}
		}
		else
		{
			if (CheckCollisionRecs(quad, p->get_hit_box()))
			{
				time_break = true;
				break;
			}
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