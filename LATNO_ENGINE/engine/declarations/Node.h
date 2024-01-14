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
	class Node
	{
	public:
		float gCost; // Distance from starting node
		float hCost; // Distance from end node
		float fCost; // g + h;
		Coords pos;
		Node* parentPtr;
		bool traversable = true;

		Node(float x, float y)
		{
			pos = Coords(x,y);
			gCost = NULL;
			hCost = NULL;
			fCost = NULL;
		}
		Node(Coords _pos)
		{
			pos = _pos;
			gCost = NULL;
			hCost = NULL;
			fCost = NULL;
		}
		Node()
		{
			pos = 0;
			gCost = NULL;
			hCost = NULL;
			fCost = NULL;
		}

		void SetCosts(Coords start, Coords pos, Coords dest)
		{

			// Calculate gCost. For diagonal movement, use a different cost.
			float diagonalCost = std::sqrt(2); // Cost for diagonal movement
			int dx = std::abs(pos.x - start.x);
			int dy = std::abs(pos.y - start.y);
			int minD = std::min(dx, dy);
			int straightD = dx + dy;
			gCost = minD * diagonalCost + (straightD - 2 * minD);

			// Use Euclidean distance for hCost (heuristic cost).
			hCost = std::sqrt(std::pow(dest.x - pos.x, 2) + std::pow(dest.y - pos.y, 2)); // Euclidean distance to destination

			CalcFCost(); // Total cost
		}

		void CalcFCost()
		{
			fCost = gCost + hCost;
		}
	};
}