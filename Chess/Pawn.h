#pragma once
#include "Piece.h"

//This class represents the piece Pawn on a chess game
class Pawn : public Piece
{
private:
	bool first_time_moving{ true };

	//Those rectangles are needed to check if the pawn can attack
	//The pawn can only attack diagonally one postision up
	Rectangle attack_rec_left{ 0,0, 100,100 };
	Rectangle attack_rec_right{ 0,0, 100,100 };

	//This is used when the Pawn becomes a queen at the end of the board
	class Queen* inner_queen = nullptr;
	void become_queen(std::vector<Piece*>&pieces);
public:
	Pawn(char col, int row, bool team);
	~Pawn();
	std::vector <Rectangle> calculate_range(std::vector<Piece*> pieces) override;
	void move(char col, int row, std::vector<Piece*>& pi) override;
};