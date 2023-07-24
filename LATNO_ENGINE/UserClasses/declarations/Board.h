#pragma once
#include "../../engine/declarations/Engine.h"
#include "Square.h"

class Board
{
public:
	Square squares[8][8];

	Board();

	std::vector<Latno::Actor> initBoard(Latno::Coords startPos);




	
};