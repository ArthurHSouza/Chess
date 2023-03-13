#pragma once
#include "raylib.h"
#include <string>
#include <vector>

class Piece
{
protected:
	Color faded_green;
	Color piece_color;
	std::string path_image;
	Texture2D pieceImage;
	
	bool is_white{false};
	bool is_selected{ false };
	bool time_break{ false };
	
	int value{};
	
	char col;
	int row;
	
	Rectangle hitbox{ 0,0,128,128 };
	Rectangle range_quad{ 14,270,100,100 };
	Rectangle range_quad_left{ 14,270,100,100 };
	std::vector<Rectangle> range_quads;
	
	int max_range {10};

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

	Rectangle get_hit_box() const;

	bool get_team() const;
	bool get_is_selected() const;

	int get_piece_value() const;

	void set_selected();
	void set_selected(bool val);
};

