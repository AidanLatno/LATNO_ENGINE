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
		float gCost; // Distance from starting node
		float hCost; // Distance from end node
		float fCost; // g + h;
		int parentX;
		int parentY;
		bool open = true;

		Node()
		{
			gCost = NULL;
			hCost = NULL;
			fCost = NULL;
		}

		void CalcFCost()
		{
			fCost = gCost + hCost;
		}
	};
}