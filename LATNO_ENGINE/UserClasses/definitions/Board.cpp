#include "../declarations/Board.h"

Board::Board()
{

}

std::vector<Latno::Actor> Board::initBoard(Latno::Coords startPos)
{
	std::vector<Latno::Actor> list;


	bool swap = true;

	int distance = 44;

	Latno::Coords temp[8][8];

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (swap) list.push_back(Latno::Actor(x * distance + startPos.x, y * distance + startPos.y, "resources/textures/white-square.png"));
			else list.push_back(Latno::Actor(x * distance + startPos.x, y * distance + startPos.y, "resources/textures/black-square.png"));

			temp[y][x] = {x*distance+startPos.x,y * distance + startPos.y};

			swap = !swap;
		}
		swap = !swap;
	}


	return list;
}