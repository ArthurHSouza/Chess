#include "Board.h"

Board::Board() {
	boardImage = LoadTexture("assets/board.png");
	std::vector<Rec>vec;
	for (int j = 0; j <= 8; j++)
	{
		vec.push_back(rec);
	}
	for (char i = 'A'; i <= 'H'; i++)
	{
		quads.insert(std::pair<char, std::vector<Rec>>(i, vec));
	}
}
Board::~Board() { UnloadTexture(boardImage); }

void Board::Draw()
{
	DrawTexture(boardImage, 0, 0, WHITE);
}
void Board::printa()
{
	std::cout << std::endl;
	for (char a = 'A'; a <= 'H'; a++)
	{
		std::cout << a << ": ";
		for (int i = 0; i < 9; i++)
			std::cout << quads.at(a).at(i).free << " ";
	}
}
std::map<char, std::vector<bool>>& Board::GetQuadss()
{
	return quadss;
}

std::map<char, std::vector<Rec>>& Board::GetQuads()
{
	return quads;
}

