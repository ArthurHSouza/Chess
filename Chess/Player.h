#pragma once
#include "raylib.h"
#include <vector>

class Player
{
private:
	//The player is controling the white pieces?
	bool control_white{};

	//Location wich the player selected
	char selected_col{};
	int selected_row{};

	class Piece* selected_piece{nullptr};
	std::vector<Rectangle> range_of_selected_piece{};

public:
	Player(bool control_white);
	~Player();
	Piece* select_piece(std::vector<Piece*>& p);
	bool select_pos_to_move(Piece* p, std::vector<Piece*>& pi, std::vector<Rectangle>pos_quads);
	std::vector<Rectangle> get_range_of_selected_piece() const;

};

