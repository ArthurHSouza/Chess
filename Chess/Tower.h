#pragma once
#include "Piece.h"

//A class that represents the Tower
class Tower : public Piece
{
public:
	Tower(char col, int row, bool team);
	std::vector <Rectangle> calculate_range(std::vector<Piece*> pieces) override;
};

