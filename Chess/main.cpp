#include "raylib.h"
#include <iostream>
#include <vector>
#include <map>
#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Board.h"
#include "Player.h"


int main()
{
	
	InitWindow(1024, 1024, "Chess");

	Player player;
	Board b;

	Piece* selected_piece;

	Piece* p1 = new Pawn('A', 1, false);
	Piece* p2 = new Pawn('B', 1, false);
	Piece* p3 = new Pawn('C', 1, false);
	Piece* p4 = new Pawn('D', 3, true);
	Piece* p5 = new Pawn('E', 2, true);
	Piece* p6 = new Pawn('F', 1, false);
	Piece* p7 = new Pawn('G', 1, false);
	Piece* p8 = new Pawn('H', 1, false);
	Piece* p9 = new Pawn('B', 6, true);
	Piece* b1 = new Bishop('C', 2, true);

	std::vector<Piece*> pieces = { p1, p2 , p3, p4, p5, p6, p7, p8, p9, b1};
	
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);
		b.Draw();

		
		selected_piece = player.select_piece(pieces); //nullptr
		
		for (auto p: pieces)
		{
	//		p->selection(blackPieces);
			p->draw();
			//p->draw_range();
		}

		if (selected_piece != nullptr)
		{
			selected_piece->draw_range();
		}
		EndDrawing();
		
	}
	for (auto p : pieces)
	{
		delete p;
	}
	return 0;
}