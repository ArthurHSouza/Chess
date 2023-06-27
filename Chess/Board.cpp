#include "Board.h"

Board::Board() {
	boardImage = LoadTexture("assets/board.png");
}
Board::~Board() { 
	UnloadTexture(boardImage); 
}

void Board::Draw()
{
	DrawTexture(boardImage, 0, 0, WHITE);
}
