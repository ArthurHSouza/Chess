#pragma once
#include "raylib.h"
#include "Board.h"
#include <string>
#include <iostream>
#include <vector>

class Piece
{
private:
	bool alive {true};
protected:
	std::string path_image;
	Texture2D pieceImage;
	
	bool is_selected{ false };
	int value{};
	std::map<char, std::vector<Rec>> quad;
	char col;
	int row;
	Rectangle hitbox{ 0,0,128,128 };
	//range
	Rectangle range_quad{ 14,270,100,100 };
	std::vector<Rectangle> range_quads;
	int range = 2;

public:
	Piece(char col, int row, std::string path);
	virtual ~Piece();

	void draw();

	virtual void move(char col, int row);
	virtual std::vector<Rectangle> selected(std::vector<Piece*> pieces);
	Rectangle get_hit_box();

	void set_selected();
	void set_selected(bool bal);

	/*
	bool alive{ true };
	bool isWhite{ false };
	int value{};
	float range{};
protected:
	int posY{};
	int posX{};
	Rectangle hitBox{ (float)posX, (float)posY, 128, 128};
	Rectangle rangeBox{ (float)posX, (float)posY,100, 100 };
	bool selected{ false };


public:
	Piece(int posX, int posY, Texture2D image);
	virtual ~Piece();
	//virtual bool move();
	virtual bool move(std::map<char, std::vector<Rec>>& b);
	void draw();
	virtual bool  selection(std::vector<Piece*>others, float& place);
	bool get_selected();
	Rectangle get_hit_box();

};*/
};

