#pragma once
#include "Piece.h"
class Horse : public Piece
{
public:
	Horse(char col, int row, bool team);

	std::vector <Rectangle> calculate_range(std::vector<Piece*> pieces) override;
};

