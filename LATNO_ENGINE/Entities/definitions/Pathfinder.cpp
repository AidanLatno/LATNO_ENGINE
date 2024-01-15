#include "../declarations/Pathfinder.h"


// Has useful psuedo code and explainations
// https://www.youtube.com/watch?v=-L-WgKMFuhE

namespace Latno
{
	Node* SmallestInList(std::vector<Node*> &list)
	{
		Node* node = list[0];
		float lowestFCost = FLT_MAX;
		for (Node*& n : list)
		{
			if (n->fCost < lowestFCost)
			{
				node = n;
				lowestFCost = node->fCost;
			}
		}
		return node;
	}
	bool IsIn(std::vector<Node*> list, Node* node)
	{
		return std::find(list.begin(), list.end(), node) != list.end();
	}

	std::vector<Coords> Pathfinder::GetPath(Coords dest)
	{
		int y = actorRef->currentScene->sizeY;
		int x = actorRef->currentScene->sizeX;
	
		grid.resize(actorRef->currentScene->sizeY, std::vector<Node>(actorRef->currentScene->sizeX));


		std::vector<Coords> THEpath = FindPath(dest, actorRef->GetPos());
		path.clear();
		return THEpath;
	}

		std::vector<Coords> THEpath = FindPath(dest, actorRef->GetPos());
		path.clear();
		return THEpath;
	}

	std::vector<Coords> Pathfinder::FindPath(Coords dest, Coords start)
	{
		Node* Current;
		std::vector<Node*> openList, closedList;
		openList.push_back(&grid[start.y][start.x]);

		while (true)
		{
			// Set current to smallest in list
			//Current = SmallestInList(openList);
			
			float lowestFCost = FLT_MAX;
			for (Node*& n : openList)
			{
				if (n->fCost < lowestFCost)
				{
					Current = n;
					lowestFCost = Current->fCost;
				}
			}

			// Erase current from OPEN
			auto it = std::find(openList.begin(), openList.end(), Current);
			if (it != openList.end()) { openList.erase(it); }

			closedList.push_back(Current);

			if (Current == &grid[dest.y][dest.x])
			{
				Current->parentPtr;

				for (Node* i = Current; i != NULL; )
				{
					path.push_back(i->pos);
					i = i->parentPtr;
				}
				return path;
			}


			// Check and update neighbors
			for (int dx = -1; dx <= 1; dx++)
			{
				for (int dy = -1; dy <= 1; dy++)
				{
					if (dx == 0 && dy == 0) continue; // Skip the current node itself

					int newX = Current->pos.x + dx;
					int newY = Current->pos.y + dy;

					// Check boundaries
					if (newX < 0 || newX >= WINDOW_LENGTH || newY < 0 || newY >= WINDOW_HEIGHT) continue;

					Node* neighbor = &grid[newY][newX];

				if (!node->traversable || IsIn(closedList, node)) continue;

				if (!IsIn(openList, node)) // This should also check if the new path is shorter but IDK how to do that yet
				{
					node->parentPtr = Current;
					if (!IsIn(openList, node))
						openList.push_back(node);
				}
			}

		}

		
		return path;
	}

	

	Pathfinder::~Pathfinder()
	{

	}
};