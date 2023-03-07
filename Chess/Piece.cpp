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

void Piece::move(char col, int row, std::vector<Piece*>& pi)
{
	return;
}

std::vector<Rectangle> Piece::calculate_range(std ::vector<Piece*> pieces)
{
	std::vector<Rectangle>rec;
	return rec;
}

void Piece::draw()
{
	if (alive == true)
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
	else
		std::cout << "MORTO";
}

int Piece::get_pos_col(char* col)
{
	*col = this->col;
	return row;
}

Rectangle Piece::get_hit_box()
{
	return hitbox;
}

bool Piece::verify_collision(std::vector<Piece*> pi)
{

	for (auto p : pi)
	{
		//if(p->get_team() == )
		if (p->get_hit_box().x == hitbox.x && p->get_hit_box().y == hitbox.y)
			continue;
		if (CheckCollisionRecs(range_quad, p->get_hit_box()))
			return true;
	}
	return false;
}

bool Piece::get_team() const
{
	return is_white;
}

bool& Piece::set_alive()
{
	return alive;
}

bool Piece::get_is_selected() const
{
	return is_selected;
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

void Piece::draw_range()
{
	if(is_selected == true)
		for (Rectangle& r : range_quads)
		{
			DrawRectangleRec(r, fade_green);
		}
}
