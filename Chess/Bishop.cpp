#include "Bishop.h"

//Bishop::Bishop(int posX, int posY) : posX{ posX }, posY{ posY }, Piece{ posX, posY, LoadTexture("assets/bishop.png") }

/*
bool Bishop::move(std::map<char, std::vector<Rec>>& b)
{
	std::cout << "BISHOP MOVE" << std::endl;
	for (float i = 0; i < range; i++)
	{
		rangeBox.y = posY+(128*(i + 1));
		rangeBox.x = posX + (128 * (i + 1));
		DrawRectangleRec(rangeBox, GREEN);
		if (CheckCollisionPointRec(GetMousePosition(), rangeBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
		{
			std::cout << "CLICOU";
			
			Piece::selected = false;
			//Piece::posY += 128 * (i + 1);
			Piece::posX = rangeBox.x;
			Piece::posY = rangeBox.y;
			Piece::hitBox.y = Piece::posY;
			Piece::hitBox.x = Piece::posX;
			
			return true;
		}
	}


}*/