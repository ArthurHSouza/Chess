#include "raylib.h"
#include <iostream>
#include <vector>
#include <map>
#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Board.h"

class GameMode
{
private:


public:
	GameMode();
	~GameMode();
	void select_piece(std::vector<Piece*> p, std::map<char, std::vector<Rec>>& b);
	void select_pos_to_move(Piece* p,std::vector<Rectangle>pos_quads);
};

GameMode::GameMode()
{
}

GameMode::~GameMode()
{
}
void GameMode::select_piece(std::vector<Piece*> p, std::map<char, std::vector<Rec>>& b)
{/*
	Rectangle hitBox;
	for (auto p : pi)
	{
		hitBox = p->get_hit_box();
		if ((CheckCollisionPointRec(GetMousePosition(), hitBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) || p->get_selected() == true)
		{
			float a {};
			//p->set_false();
			if(p->selection(pi,a) == true)
				p->move(b);
			std::cout << a;

		}
	}
*/

	for (int i {}; i < p.size(); i++)
	{

		if (CheckCollisionPointRec(GetMousePosition(), (p.at(i)->get_hit_box())) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			for (int j{}; j < p.size(); j++)
				if (j == i)
					continue;
				else
					p.at(j)->set_selected(false);

			p.at(i)->set_selected();
			
		}
		select_pos_to_move(p.at(i), p.at(i)->selected(p));
		
	}
}

void GameMode::select_pos_to_move(Piece* p, std::vector<Rectangle> pos_quads)
{
	for(int i {}; i < pos_quads.size(); i++)
		if (CheckCollisionPointRec(GetMousePosition(), pos_quads.at(i)) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			char col{};
			int row{};
			for (int j = 0; j < 8; j++)
			{
				if (pos_quads.at(i).y > (128*j) && ((128 * (j + 1)) > pos_quads.at(i).y))
				{
					row = j;
					break;
				}

			}
			for (int j = 0; j < 8; j++)
			{
				if (pos_quads.at(i).x > (128 * j) && ((128 * (j + 1)) > pos_quads.at(i).x))
				{
					col = j+65;
					break;
				}

			}
			p->move(col, row);
			p->set_selected();
			return;
		}
}


int main()
{
	InitWindow(1024, 1024, "Chess");

	GameMode g;
	Board b;
	Piece* p1 = new Pawn('A', 1);
	Piece* p2 = new Pawn('B', 1);
	Piece* p3 = new Pawn('C', 1);
	Piece* p8 = new Pawn('E', 1);
	Piece* p4 = new Pawn('D', 1);
	Piece* p5 = new Pawn('F', 1);
	Piece* p6 = new Pawn('G', 1);
	Piece* p7 = new Pawn('H', 1);
	//Piece* b1 = new Bishop(384, 0);
	std::vector<Piece*> blackPieces = { p1, p2, p3, p4, p5, p6, p7, p8};

	while (!WindowShouldClose())
	{

		BeginDrawing();

		ClearBackground(BLACK);
		b.Draw();
		//b.GetQuads().at('A').at(0) = true;
		//b.printa();
		//b1->selection(blackPieces);
		//b1->draw();

		
		for (auto p: blackPieces)
		{
	//		p->selection(blackPieces);
			p->draw();
		}

		g.select_piece(blackPieces, b.GetQuads());
		EndDrawing();
		
	}
	for (auto p : blackPieces)
	{
		delete p;
	}
	return 0;
}