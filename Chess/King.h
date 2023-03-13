#pragma once
#include "Piece.h"

//A class that represents the King
class King : public Piece
{
private:
	//Color used in the function draw check
	Color faded_red{};
	bool is_on_check{ false };

public:
	King(char col, int row, bool team);

	bool get_is_on_check();
	void set_is_on_check(bool val);

	//Fill the hitbox with red when the king is on check
	void draw_check();
};

