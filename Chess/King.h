#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(char col, int row, bool team);
	std::vector <Rectangle> calculate_range(std::vector<Piece*> pieces) override;
};

