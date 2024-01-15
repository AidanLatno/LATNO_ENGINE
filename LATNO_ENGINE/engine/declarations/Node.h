#pragma once
#include "Coords.h"
namespace Latno
{
	/*
	* Class Name: Node
	* Purpose: Used for the A* path tracing algorithm
	* 
	* variables:
	*	gCost
	*		- Distance from starting node
	*	hCost 
	*		_ Distance from end node
	*	fCost 
	*		- gCost + hCost;
	* methods:
	*	 CalcFCost()
	*		- Calculates the fCost
	*/
	class Node {
	public:
		int x, y;
		int gCost, hCost, fCost;
		Node* parent;
		bool isTraversable = true;

		Node(int x, int y) : x(x), y(y), gCost(INT_MAX), hCost(0), fCost(0), parent(nullptr) {}

		void calculateCosts(Node* endNode) {
			hCost = std::abs(x - endNode->x) + std::abs(y - endNode->y); // Manhattan distance
			fCost = gCost + hCost;
		}
	};
}