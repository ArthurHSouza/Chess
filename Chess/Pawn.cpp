#include "Pawn.h"
#include "Board.h"


Pawn::Pawn(char col, int row, bool team):
	Piece::Piece(col, row, team,"assets/pawn.png")
{
	value = 5;
	range = 2;
}

Pawn::~Pawn()
{

}

std::vector < Rectangle> Pawn::calculate_range(std::vector<Piece*> pieces)
{
	time_break = false;
	int a = 0; //debug

	//std::vector<Piece>

	if (is_selected == true)
	{
		if (first_time_moving == false)
			range = 1;
		
		std::cout << "Esta seleceionado" << std::endl;

		range_quad.x = (float)( (col%65) *128 +14);
		for (int i = 0; i < range; i++)
		{
			
			std::cout << "Esta dentro do for" << std::endl;

			if (is_white == true)
			{
				range_quad.y = (float)(128 * (row - i - 1) + 14);
			}
			else
				range_quad.y = (float)(128 * (row + i + 1) + 14);

			for (const auto p : pieces)
			{
				a++;
				
				if (p->get_team() != is_white)
				{
					//debug
					//std::cout << "BLACK BOX X: " << p->get_hit_box().x << "BLACK BOX Y: " << p->get_hit_box().y << std::endl;
					if (is_white == true)
					{
						attack_rec_right.y = (row - 1) * 128 + 14;
						//std::cout << attack_rec_right.y << std::endl;
						attack_rec_left.y = (row - 1) * 128 + 14;
					}
					else
					{
						attack_rec_right.y = (row + 1) * 128 + 14;
						attack_rec_left.y = (row + 1) * 128 + 14;
					}

					attack_rec_right.x = (col % 65) * 128 + 128 + 14;
					attack_rec_left.x = (col % 65) * 128 - 128 + 14;

					if (CheckCollisionRecs(attack_rec_right, p->get_hit_box()) == true)
					{
						std::cout << "dentro";
						range_quads.push_back(attack_rec_right);
					}
					if (CheckCollisionRecs(attack_rec_left, p->get_hit_box()) == true)
					{
						range_quads.push_back(attack_rec_left);
					}
				
				}
				if (CheckCollisionRecs(range_quad, p->get_hit_box()) == true)
				{
				
					std::cout << "SAINDO PELO BREAK" << std::endl;
					std::cout << "PECA DO BO: " << p->get_hit_box().x << " " << p->get_hit_box().y <<" " << p->get_team() << " " << is_white << std::endl;
					time_break = true;
					break;
				}
			}
		if (time_break)
			break;
		range_quads.push_back(range_quad);
		}

		/*
		for (Rectangle& r : range_quads)
		{
			DrawRectangleRec(r, fade_green);
		}
		*/
	}
	else
	{
		if(range_quads.empty() == false)
			range_quads.clear();
	}
	std::cout << pieces.size() << " " << a << " " << std::endl;
	std::cout << range_quads.size() << std::endl;
	return range_quads;
}

void Pawn::move(char col, int row, std::vector<Piece*>& pi)
{
	this->col = col;
	this->row = row;
	first_time_moving = false;

	range_quads.clear(); //delete and try

	char* o_col = new char;
	int o_row = 0;

	for (int i = 0; i < pi.size(); i++)
	{
		o_row = pi.at(i)->get_pos_col(o_col);
		if (pi.at(i)->get_team() != is_white)
		{
			if (this->col == *(o_col) && this->row == o_row)
			{
				delete pi.at(i);
				pi.erase(pi.begin() + i);
			}
		}
	}
	delete o_col;

}
