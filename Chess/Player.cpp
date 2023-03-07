#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}
Piece* Player::select_piece(std::vector<Piece*>& p)
{

	for (int i{}; i < p.size(); i++)
	{
		if (p.at(i)->get_team() != is_white)
			continue;

		if ((CheckCollisionPointRec(GetMousePosition(), (p.at(i)->get_hit_box())) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
		{
			for (int j{}; j < p.size(); j++)
				if (j == i)
					continue;
				else
					p.at(j)->set_selected(false);

			p.at(i)->set_selected();

			range_of_selected_piece = p.at(i)->calculate_range(p);
			//std::cout << range_of_piece.size() << std::endl;

			selected_piece = p.at(i);
			//select_pos_to_move(p.at(i),p, range_of_piece);
			//return p.at(i);
		}


	}
	if (selected_piece)
	{
		select_pos_to_move(selected_piece, p, range_of_selected_piece);
		return selected_piece;
	}

	
	return nullptr;
}

bool Player::select_pos_to_move(Piece* p, std::vector<Piece*>& pieces, std::vector<Rectangle> pos_quads)
{
	//selected_col = 0;
	//selected_row = 0;

	//std::cout << "Tamanho" << pos_quads.size() << std::endl;
	for (int i{}; i < pos_quads.size(); i++)
		if (CheckCollisionPointRec(GetMousePosition(), pos_quads.at(i)) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			//debug
			//std::cout << "Dentro: Tamanho do vetor" << pos_quads.size() << std::endl;
			/*
			std::cout << std::endl;
			for (Rectangle r : pos_quads)
			{
				std::cout << "X: " << r.x << " Y: " << r.y << std::endl;
			}*/
			for (int j = 0; j < 8; j++)
			{
				if (pos_quads.at(i).y > (128 * j) && ((128 * (j + 1)) > pos_quads.at(i).y))
				{
					selected_row = j;
					break;
				}

			}
			for (int j = 0; j < 8; j++)
			{
				if (pos_quads.at(i).x > (128 * j) && ((128 * (j + 1)) > pos_quads.at(i).x))
				{
					selected_col = j + 65;
					break;
				}

			}

			p->move(selected_col, selected_row, pieces);

			p->set_selected();
			return true;
		}
	return false;
}
