#pragma once

#include "../../engine/declarations/Engine.h"

enum Color
{
	BLACK = 0,
	WHITE = 1
};

class Piece : public Latno::Actor
{
public:
	Color color;

	Latno::Coords boardPos;
	std::string notation;


	virtual std::vector<Latno::Coords>* getMoves() { std::cout << "No Moves Overriden"; return nullptr; }

	
};
