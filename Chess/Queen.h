#pragma once
#include "Piece.h"

//This class represent the Queen
class Queen : public Piece
{
public:
	Queen(char col, int row, bool team);
	~Queen() = default;
};

