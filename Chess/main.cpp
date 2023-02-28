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
	char selected_col{};
	int selected_row{};

public:
	GameMode();
	~GameMode();
	void select_piece(std::vector<Piece*>& p, std::map<char, std::vector<Rec>>& b);
	void select_pos_to_move(Piece* p, std::vector<Piece*>& pi,std::vector<Rectangle>pos_quads);
};

GameMode::GameMode()
{
}

GameMode::~GameMode()
{
}
void GameMode::select_piece(std::vector<Piece*>& p, std::map<char, std::vector<Rec>>& b)
{

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
		select_pos_to_move(p.at(i),p, p.at(i)->selected(p));
		
	}
}

void GameMode::select_pos_to_move(Piece* p, std::vector<Piece*>& pi, std::vector<Rectangle> pos_quads)
{
	//selected_col = 0;
	//selected_row = 0;
	for(int i {}; i < pos_quads.size(); i++)
		if (CheckCollisionPointRec(GetMousePosition(), pos_quads.at(i)) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{

			for (int j = 0; j < 8; j++)
			{
				if (pos_quads.at(i).y > (128*j) && ((128 * (j + 1)) > pos_quads.at(i).y))
				{
					selected_row = j;
					break;
				}

			}
			for (int j = 0; j < 8; j++)
			{
				if (pos_quads.at(i).x > (128 * j) && ((128 * (j + 1)) > pos_quads.at(i).x))
				{
					selected_col = j+65;
					break;
				}

			}

			p->move(selected_col, selected_row, pi);
			
			p->set_selected();
			return;
		}
}


int main()
{
	InitWindow(1024, 1024, "Chess");

	GameMode g;
	Board b;
	Piece* p1 = new Pawn('A', 1, false);
	Piece* p2 = new Pawn('B', 1, false);
	Piece* p3 = new Pawn('C', 1, false);
	Piece* p4 = new Pawn('D', 1, false);
	Piece* p5 = new Pawn('E', 1, false);
	Piece* p6 = new Pawn('F', 1, false);
	Piece* p7 = new Pawn('G', 1, false);
	Piece* p8 = new Pawn('H', 1, false);
	//Piece* b1 = new Bishop(384, 0);
	std::vector<Piece*> blackPieces = { p1, p2 , p3, p4, p5, p6, p7, p8};

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);
		b.Draw();


		
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