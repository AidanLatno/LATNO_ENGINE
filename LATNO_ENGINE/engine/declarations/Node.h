#pragma once

class Node
{
public:
	Coords pos;
	int gCost; // Distance from starting node
	int hCost; // Distance from end node
	int fCost; // g + h;
	Node* parentNode;

	Node()
	{
		gCost = NULL;
		hCost = NULL;
		fCost = NULL;
	}

	void CalcFCost()
	{
		fCost = gCost = hCost;
	}
};