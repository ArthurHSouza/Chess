#include "Piece.h"

Piece::Piece(char col, int row, bool team, std::string path) :
	col{ col }, row{ row }, is_white{team}, path_image{path}
{
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

std::vector<Rectangle> Piece::selected(std ::vector<Piece*> pieces)
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


void Piece::set_selected()
{
	is_selected = !is_selected;
}
void Piece::set_selected(bool val)
{
	is_selected = val;
}

/*
bool Piece::move(std::map<char, std::vector<Rec>>& b)
{/*
	for (float i = 0; i < range; i++)
	{
		rangeBox.y = 256 + (128 * i);
		rangeBox.x = posX;
		DrawRectangleRec(rangeBox, GREEN);
		if (CheckCollisionPointRec(GetMousePosition(), rangeBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
		{
			posY = (int)rangeBox.y;
			hitBox.y = (int)rangeBox.y;
			selected = false;
		}
	}
	std::cout << "BASE";
	return true;
}
void Piece::draw()
{
	if(alive == true)
		if(isWhite == true)
			DrawTexture(pieceImage, posX, posY, LIGHTGRAY);
		else
			DrawTexture(pieceImage, posX, posY, BLACK);
}

bool Piece::selection(std::vector<Piece*>pieces, float& place)
{
	return true;
}

bool Piece::get_selected()
{
	return selected;
}

Rectangle Piece::get_hit_box()
{
	return hitBox;
}
*/