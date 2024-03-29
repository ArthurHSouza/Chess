#include "Player.h"
#include "Piece.h"

Player::Player(bool control_white) : control_white{control_white}
{

}

Player::~Player()
{
	delete selected_piece;
}
Piece* Player::select_piece(std::vector<Piece*>& p)
{
	for (int i{}; i < p.size(); i++)
	{
		if (p.at(i)->get_team() != control_white)
			continue;

		if ((CheckCollisionPointRec(GetMousePosition(), (p.at(i)->get_hitbox())) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
		{
			for (int j{}; j < p.size(); j++)
				if (j == i)
					continue;
				else
					p.at(j)->set_selected(false);

			p.at(i)->set_selected();

			range_of_selected_piece = p.at(i)->calculate_range(p);

			selected_piece = p.at(i);
		}
	}
	if (selected_piece)
	{
		return selected_piece;
	}

	return nullptr;
}

bool Player::select_pos_to_move(Piece* p, std::vector<Piece*>& pieces, std::vector<Rectangle> pos_quads)
{
	for (int i{}; i < pos_quads.size(); i++)
		if (CheckCollisionPointRec(GetMousePosition(), pos_quads.at(i)) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
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
			selected_piece = nullptr;
			p->set_selected();
			return true;
		}
	return false;
}

std::vector<Rectangle> Player::get_range_of_selected_piece() const
{
	return range_of_selected_piece;
}
