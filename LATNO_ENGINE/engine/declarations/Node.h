#pragma once

#include <Coords.h>
#include <Scene.h>

class Node
{
	Coords pos;
	//int arrayOfBestPath[ *Scene x* ][ *Scene y* ];
	int g, h;
	int f = g + h;

	void UpdateCosts(Coords playerPos, Coords targetPos);

};