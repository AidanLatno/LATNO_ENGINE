#pragma once
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
}