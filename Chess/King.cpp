#include "King.h"

King::King(char col, int row, bool team) : Piece::Piece(col, row, team, "assets/king.png")
{
	value = 10;
	max_range = 1;
	faded_red = Fade(MAROON, 0.8f);
}

bool King::get_is_on_check()
{
	return is_on_check;
}

void King::set_is_on_check(bool val)
{
	is_on_check = val;
}

void King::draw_check()
{
	DrawRectangleRec(get_hitbox(), faded_red);
}
