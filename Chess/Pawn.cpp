#include "Pawn.h"
#include "Board.h"
/*
Pawn::Pawn(int posX, int posY) : posX{ posX }, posY{ posY }, Piece{ posX, posY, LoadTexture("assets/pawn.png") }
{
	pieceImage = LoadTexture("assets/pawn.png");
}
Pawn::~Pawn()
{
	UnloadTexture(pieceImage);
}
*/

/*
void Pawn::draw()
{
	if (alive == true)
		DrawTexture(pieceImage, posX, posY, WHITE);
}


bool Pawn::move(std::map<char, std::vector<Rec>>& b)
{
	std::cout << "Move";

	/*
	for (float i = 0; i < range; i++)
	{
		rangeBox.y = startYRangeBox + 14 + (128 * i);
		rangeBox.x = (int)posX + 14;
		DrawRectangleRec(rangeBox, GREEN);
		if (CheckCollisionPointRec(GetMousePosition(), rangeBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
		{
			/*
			std::cout << std::endl << "VOCE CLICOU NO VERDE" << posY << rangeBox.y << std::endl;
			Piece::posY = (int)rangeBox.y;
			Piece::hitBox.y = (int)rangeBox.y;
			startYRangeBox = (int)rangeBox.y + 128;
			Piece::selected = false;
			
			Piece::selected = false;
			Piece::posY += 128*(i+1);
			Piece::hitBox.y = Piece::posY;
			startYRangeBox = Piece::posY+128;
			firstMove = false;
			return true;
		}
	}
	
	return true;
}

bool Pawn::selection(std::vector<Piece*> others, float &place)
{

	Piece::selected = true;
	if (firstMove == true)
		range = 2.f;
	else range = 1.f;

	for (float i = 0; i < range; i++)
	{
		rangeBox.y = startYRangeBox + 14 + (128 * i);
		rangeBox.x = (int)posX + 14;
		DrawRectangleRec(rangeBox, GREEN);
		if (CheckCollisionPointRec(GetMousePosition(), rangeBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
		{
			//place = new float;
			place = startYRangeBox + 14 + (128 * i);
			return true;
		}
	}
	return false;
}
*/

Pawn::Pawn(char col, int row):
	Piece::Piece(col, row, "assets/pawn.png")
{
	value = 1;
}

Pawn::~Pawn()
{

}

std::vector < Rectangle> Pawn::selected(std::vector<Piece*> pieces)
{
	bool time_break = false;

	if (is_selected == true)
	{
		if (first_time_moving == false)
			range = 1;
		range_quad.x = (float)( (col%65) *128 +14);

		for (int i = 0; i < range; i++)
		{
			range_quad.y = (float)(128 * (row + i + 1) + 14);
			for (auto p : pieces)
			{

				if (p->get_hit_box().x == hitbox.x && p->get_hit_box().y == hitbox.y)
					continue;
				if (CheckCollisionRecs(range_quad, p->get_hit_box()) == false)
				{
					range_quads.push_back(range_quad);
				}
				else
					time_break = true;
			}
			if (time_break == true)
				break;
		}
		for (Rectangle& r : range_quads)
		{
			DrawRectangleRec(r, GREEN);
		}
	}
	return range_quads;
}

void Pawn::move(char col, int row)
{
	this->col = col;
	this->row = row;
	first_time_moving = false;
	range_quads.clear();
}
