#include "raylib.h"
#include <iostream>
#include <vector>
#include <map>
#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Board.h"
#include "Player.h"
#include "Horse.h"
#include "Tower.h"
#include "Queen.h"
#include "King.h"


bool check(std::vector<Piece*> pieces, King* k)
{
	int a {}; //debug
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
		if (p->get_piece_value() == 7)
		{

			//std::cout << std::endl << "TAMANHO DO ALCANCE DENTRO DA FUNCAO " << rec.size() << " Quantidade de pecas " << pieces.size() << std::endl;
		}
		for (const auto r : rec)
		{
			if (p->get_piece_value() == 7)
			{
				//std::cout << ++a << " X do quad: " << r.x << " Y do quad: " << r.y << std::endl;
			}
			//if (r.x > k->get_hit_box().x && r.x < k->get_hit_box().x + 120 && r.y > k->get_hit_box().y && r.y < k->get_hit_box().y + 120)
				//std::cout << std::endl << p->get_piece_value() << std::endl;
			if ((r.x - 14) == k->get_hit_box().x && (r.y - 14) == k->get_hit_box().y)
			{
				std::cout << std::endl << "Peca q ta mirando no rei " <<  p->get_piece_value() << std::endl;
				return true;
			}
			if (CheckCollisionRecs(r, k->get_hit_box()))
			{
				//std::cout << "X do quad: " << r.x << "Y do quad: " << r.y << "X do Rei: " << k->get_hit_box().x << "Y do Rei: " << k->get_hit_box().y
					//<< " " << p->get_piece_value() << std::endl;
			}
		}
		a = 0;
		
		rec.clear();
		

	}
	return false;
}

int verify_end_game(std::vector<Piece*> pieces)
{
	int counter{};
	bool winner_team{};
	for (const auto p : pieces)
	{
		if (p->get_piece_value() == 10)
		{
			counter++;
			winner_team = p->get_team();
		}
	}
	if (counter == 1)
	{
		return (int)(winner_team)+1;
	}

	return 0;
}

int main()
{
	std::vector<Rectangle> bombom; // deletar
	InitWindow(1024, 1024, "Chess");

	Player player;
	Board b;

	Piece* selected_piece;

	Piece* p1 = new Pawn('A', 1, false);
	Piece* p2 = new Pawn('B', 1, false);
	Piece* p3 = new Pawn('C', 1, false);
	Piece* p4 = new Pawn('D', 1, false);
	Piece* p5 = new Pawn('E', 2, true);
	Piece* p6 = new Pawn('F', 1, false);
	Piece* p7 = new Pawn('G', 4, true);
	Piece* p8 = new Pawn('H', 1, false);
	Piece* p9 = new Pawn('B', 6, true);
	Piece* b1 = new Bishop('C', 2, true);
	Piece* h1 = new Horse('E', 5, true);
	Piece* t1 = new Tower('F', 4, true);
	Piece* q1 = new Queen('F', 5, true);
	Piece* k1 = new King('F', 6, false);
	
	King* black_king = static_cast<King*>(k1);

	std::vector<Piece*> pieces = { p1, p2 , p3, p4, p5, p6, p7, p8, p9, b1, h1, t1, q1, k1};

	SetTargetFPS(120);
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);
		b.Draw();

		std::cout << verify_end_game(pieces);

		if (static_cast<King*>(k1)->verify_check())
		{
			static_cast<King*>(k1)->draw_check();
		}
		

		//*k1.verify_check(pieces);
		//std::cout << *k1.get_team();
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
			if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
			{
				/*
				selected_piece->set_selected(true);
				bombom = selected_piece->calculate_range(pieces);
				std::cout << "Bombons: " << bombom.size() << std::endl;
				selected_piece->set_selected(false);
				selected_piece->clear_range_quads();
				*/
			}

			//Testar isso aqui na hora que estiver implementando o sistema de pontuação
			if (player.select_pos_to_move(selected_piece, pieces, player.get_range_of_selected_piece()))
			{
				/*
				selected_piece->clear_range_quads();
				selected_piece->set_selected(true);
				bombom = selected_piece->calculate_range(pieces);
				std::cout << "Bombons2: " << bombom.size() << std::endl;
				selected_piece->set_selected(false);
				selected_piece->clear_range_quads();
				*/
				if (check(pieces, static_cast<King*>(k1)))
					static_cast<King*>(k1)->set_is_on_check(true);
				else
					static_cast<King*>(k1)->set_is_on_check(false);
			}
		}
		EndDrawing();
		
	}
	for (auto p : pieces)
	{
		delete p;
	}
	return 0;
}