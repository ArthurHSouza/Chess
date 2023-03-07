#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>
#include "Piece.h"

class Player
{
private:
	bool control_white{ true };
	char selected_col{};
	int selected_row{};
	Piece* selected_piece{nullptr};
	std::vector<Rectangle> range_of_selected_piece{};//maybe delete

public:
	Player();
	~Player();
	Piece* select_piece(std::vector<Piece*>& p);
	bool select_pos_to_move(Piece* p, std::vector<Piece*>& pi, std::vector<Rectangle>pos_quads);

};

