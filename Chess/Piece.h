#pragma once
#include "raylib.h"
#include <string>
#include <vector>

//This class it's the super class of all other pieces
class Piece
{
protected:
	//Color used to fill the quads of the range
	Color faded_green;
	//Color of the piece, Gray (white) or Black
	Color piece_color;

	//Image that represents the piece
	Texture2D pieceImage;
	//The path where's found the image
	std::string path_image;
	
	bool is_white{false};
	bool is_selected{ false };
	//Used in the function to check the collision
	bool time_break{ false };
	
	int value{};
	
	//Column and row of the piece
	char col;
	int row;
	
	//Hitbox of the piece, the rectangle that the player must click to select the piece
	Rectangle hitbox{ 0,0,128,128 };
	//Rectangles used to calculate the range
	Rectangle range_quad{ 14,270,100,100 };
	Rectangle range_quad_left{ 14,270,100,100 };
	//A vector that puts all the quads of the range together
	std::vector<Rectangle> range_quads;
	//Max range that a piece can go
	int max_range {10};
	//Check if the range_quad is colliding with a piece of the same team
	bool check_collision(Rectangle quad, std::vector<Piece*> pieces);
public:
	Piece(char col, int row,bool team,std::string path);
	virtual ~Piece();

	void draw() const;
	void draw_range() const;

	int get_pos_col(char* col) const;

	virtual void move(char col, int row, std::vector<Piece*>& pi);

	virtual std::vector<Rectangle> calculate_range(std::vector<Piece*> pieces);
	
	void clear_range_quads();

	Rectangle get_hitbox() const;

	bool get_team() const;
	bool get_is_selected() const;

	int get_piece_value() const;

	void set_selected();
	void set_selected(bool val);
};

