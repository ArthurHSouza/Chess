#pragma once
#include "Piece.h"
class Tower : public Piece
{
public:
	Tower(char col, int row, bool team);
	std::vector <Rectangle> calculate_range(std::vector<Piece*> pieces) override;
};

