#include "Piece.h"

Piece::Piece(char col, int row, std::string path) :
	col{ col }, row{ row }, path_image{path}
{
	pieceImage = LoadTexture(path_image.c_str());
}

Piece::~Piece()
{
	UnloadTexture(pieceImage);
}

void Piece::move(char col, int row)
{
}

std::vector<Rectangle> Piece::selected(std ::vector<Piece*> pieces)
{
	std::vector<Rectangle>rec;
	return rec;
}

void Piece::draw()
{
	int pos_x{};
	int pos_y{};
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
	DrawTexture(pieceImage, (int)hitbox.x, (int)hitbox.y, BLACK);
}

Rectangle Piece::get_hit_box()
{
	return hitbox;
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