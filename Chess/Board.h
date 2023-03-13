#pragma once
#include "raylib.h"

//Class to draw the board
class Board
{
private:
	Texture2D boardImage{};

public:
	Board();
	~Board();
	void Draw();
};

