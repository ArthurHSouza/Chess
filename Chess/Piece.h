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
	Color fade_green = Fade(GREEN, 0.008f);
	std::string path_image;
	Texture2D pieceImage;
	
	bool is_white{false};
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
	Piece(char col, int row,bool team,std::string path);
	virtual ~Piece();

	void draw();
	
	int get_pos_col(char* col);

	virtual void move(char col, int row, std::vector<Piece*>& pi);
	virtual std::vector<Rectangle> selected(std::vector<Piece*> pieces);
	Rectangle get_hit_box();

	bool verify_collision(std::vector<Piece*> pi); // deletar
	bool get_team() const;
	bool& set_alive();

	void set_selected();
	void set_selected(bool bal);

};

