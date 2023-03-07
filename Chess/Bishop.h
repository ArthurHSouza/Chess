#pragma once
#include "Piece.h"

class Bishop :public Piece
{
public:
	Bishop(char col, int row, bool team);
	~Bishop();

	std::vector <Rectangle> calculate_range(std::vector<Piece*> pieces) override;
};