#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(char col, int row, bool team);
	std::vector <Rectangle> calculate_range(std::vector<Piece*> pieces) override;
};

