#include "Queen.h"

Queen::Queen(char col, int row, bool team): Piece::Piece(col, row, team, "assets/queen.png")
{
	value = 9;
}