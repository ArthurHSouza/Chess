#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>
#include <map>
struct Rec
{
	Rectangle rect{ 0,0,128,128 };
	bool free{ true };
};
class Board
{
private:
	Texture2D boardImage{};
	Rectangle hitBox{ 0, 0, 128, 128 };

	Rec rec;

	std::map<char, std::vector<Rec>>quads;

	std::map<char, std::vector<bool>> quadss = {
		{'A',{0,0,0,0,0,0,0,0}},
		{'B',{0,0,0,0,0,0,0,0}},
		{'C',{0,0,0,0,0,0,0,0}},
		{'D',{0,0,0,0,0,0,0,0}},
		{'E',{0,0,0,0,0,0,0,0}},
		{'F',{0,0,0,0,0,0,0,0}},
		{'G',{0,0,0,0,0,0,0,0}},
		{'H',{0,0,0,0,0,0,0,0}}
	};

public:
	Board();
	~Board();
	void Draw();
	void printa();
	std::map<char, std::vector<bool>>& GetQuadss();
	std::map<char, std::vector<Rec>>& GetQuads();
	void a();
};

