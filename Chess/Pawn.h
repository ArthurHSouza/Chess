#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
	bool first_time_moving{ true };
	Rectangle attack_rec_left{ 0,0, 100,100 };
	Rectangle attack_rec_right{ 0,0, 100,100 };

public:
	Pawn(char col, int row, bool team);
	~Pawn();
	std::vector <Rectangle> calculate_range(std::vector<Piece*> pieces) override;
	
	void move(char col, int row, std::vector<Piece*>& pi) override;
};