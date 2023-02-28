#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
	bool first_time_moving{ true };
	bool time_break = false;
	Rectangle attack_rec_left{ 0,0, 100,100 };
	Rectangle attack_rec_right{ 0,0, 100,100 };
	/*
	int value = 5;
	Texture2D pieceImage;
	bool selected{ false };
	bool alive{ true };
	bool isWhite{ false };
	bool firstMove{ true };
	float range{ 1 };
	int posY{};
	int posX{};
	Rectangle rangeBox{ 0, 0,100, 100 };
	int startYRangeBox = 256;
	char col = 'A';

public:
	Pawn(int posX, int posY);
	~Pawn();
	//bool move(std::map<char, std::vector<Rec>>& b);
	//virtual bool selection(std::vector<Piece*>others, float& place);
};
*/
public:
	Pawn(char col, int row, bool team);
	~Pawn();
	std::vector < Rectangle> selected(std::vector<Piece*> pieces) override;
	
	void move(char col, int row, std::vector<Piece*>& pi) override;
};