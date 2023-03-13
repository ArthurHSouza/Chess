#include "raylib.h"
#include <vector>
#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Board.h"
#include "Player.h"
#include "Horse.h"
#include "Tower.h"
#include "Queen.h"
#include "King.h"

//Verify if the king is on check
bool check(std::vector<Piece*> pieces, King* k)
{
	std::vector<Rectangle> rec{};

	for (auto p: pieces)
	{
		if (p->get_team() == k->get_team())
		{
			continue;
		}

		p->set_selected(true);
		rec = p->calculate_range(pieces);
		p->clear_range_quads();
		p->set_selected(false);

		for (const auto r : rec)
		{
			if (CheckCollisionRecs(r, k->get_hit_box()))
			{
				return true;
			}
		}
		rec.clear();
	}
	return false;
}

/*
Return 0 if the game isn't finished
Return 1 if the Black pieces win
Return 2 if the White pieces win
Return 3 if it's a draw
*/
int verify_end_game(std::vector<Piece*> pieces)
{
	int counter_kings{};
	int counter_minor_pieces{};
	bool winner_team{};
	for (const auto p : pieces)
	{
		if (p->get_piece_value() == 10)
		{
			counter_kings++;
			winner_team = p->get_team();
		}
		else
		{
			counter_minor_pieces++;
		}
	}
	if (counter_kings == 1)
	{
		return (int)(winner_team)+1;
	}
	else if (counter_minor_pieces == 0)
	{
		return 3;
	}

	return 0;
}

int main()
{
	InitWindow(1024, 1024, "Chess");
	Image icon = LoadImage("assets/pawn.png");
	SetWindowIcon(icon);

	const char* text{};
	int text_size{100};

	int game_ends{};

	bool play_time{ false };
	Player player_one(true);
	Player player_two(false);
	std::vector<Player>players{ player_one, player_two };
	Board b;

	Piece* selected_piece;

	Piece* p1 = new Pawn('A', 1, false);
	Piece* p2 = new Pawn('B', 1, false);
	Piece* p3 = new Pawn('C', 1, false);
	Piece* p4 = new Pawn('D', 1, false);
	Piece* p5 = new Pawn('E', 1, false);
	Piece* p6 = new Pawn('F', 1, false);
	Piece* p7 = new Pawn('G', 1, false);
	Piece* p8 = new Pawn('H', 1, false);

	Piece* b1 = new Bishop('C', 0, false);
	Piece* b2 = new Bishop('F', 0, false);

	Piece* h1 = new Horse('B', 0, false);
	Piece* h2 = new Horse('G', 0, false);

	Piece* t1 = new Tower('A', 0, false);
	Piece* t2 = new Tower('H', 0, false);

	Piece* q1 = new Queen('D', 0, false);
	Piece* k1 = new King('E', 0, false);
	
	Piece* p9 = new Pawn('A', 6, true);
	Piece* p10 = new Pawn('B', 6, true);
	Piece* p11 = new Pawn('C', 6, true);
	Piece* p12 = new Pawn('D', 6, true);
	Piece* p13 = new Pawn('E', 6, true);
	Piece* p14 = new Pawn('F', 6, true);
	Piece* p15 = new Pawn('G', 6, true);
	Piece* p16 = new Pawn('H', 6, true);

	Piece* b3 = new Bishop('C', 7, true);
	Piece* b4 = new Bishop('F', 7, true);

	Piece* h3 = new Horse('B', 7, true);
	Piece* h4 = new Horse('G', 7, true);

	Piece* t3 = new Tower('A', 7, true);
	Piece* t4 = new Tower('H', 7, true);

	Piece* q2 = new Queen('D', 7, true);
	Piece* k2 = new King('E', 7, true);

	King* black_king = static_cast<King*>(k1);
	King* white_king = static_cast<King*>(k2);
	std::vector<King*> kings = { white_king, black_king };

	std::vector<Piece*> pieces = { p1, p2 , p3, p4, p5, p6, p7, p8, b1,b2, h1, h2, t1, t2, q1, k1,
								   p9, p10 , p11, p12 , p13, p14, p15, p16, b3, b4, h3, h4, t3, t4, q2, k2};

	SetTargetFPS(120);
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);
		b.Draw();

		for (auto p : pieces)
		{
			p->draw();
		}

		game_ends = verify_end_game(pieces);
		switch (game_ends)
		{
		case 1:
			text = "BLACK WINS!";
			break;
		case 2:
			 text = "WHITE WINS";
			break;
		case 3:
			text = "DRAW!";
			break;
		}
		if (game_ends != 0)
		{
			DrawText(text, (GetScreenWidth()/2) - (MeasureText(text, 100) / 2), (GetScreenHeight() / 2.f) - (text_size/2), text_size, SKYBLUE);
			EndDrawing();
			continue;
		}
		for (King* k : kings)
		{
			if (k)
			{
				if (k->get_is_on_check())
				{
					k->draw_check();
				}
			}
		}
		
		selected_piece = players.at(play_time).select_piece(pieces);


		if (selected_piece)
		{
			selected_piece->draw_range();

			if (players.at(play_time).select_pos_to_move(selected_piece, pieces, players.at(play_time).get_range_of_selected_piece()))
			{
				play_time = !play_time;

				for (King* k : kings)
				{
					if (k)
					{
						if (check(pieces, k))
							k->set_is_on_check(true);
						else
							k->set_is_on_check(false);
					}
				}
			}
		}
		EndDrawing();
		
	}
	for (auto p : pieces)
	{
		delete p;
	}
	UnloadImage(icon);
	return 0;
}