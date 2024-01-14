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
	
		//grid.resize(actorRef->currentScene->sizeY/100, std::vector<Node>(actorRef->currentScene->sizeX/100));

		grid.resize(y);

		// Resize each of the inner vectors to the new X size
		for (int i = 0; i < y; ++i) {
			grid[i].resize(x);
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
			Current = SmallestInList(openList);

			// Erase current from OPEN
			auto it = std::find(openList.begin(), openList.end(), Current);
			if (it != openList.end()) { openList.erase(it); }

			closedList.push_back(Current);

			if (Current == &grid[dest.y][dest.x])
				return path;


			Node* n1 = &grid[Current->pos.y - 1][Current->pos.x - 1]; // Top left
			Node* n2 = &grid[Current->pos.y - 1][Current->pos.x]; // Top Middle
			Node* n3 = &grid[Current->pos.y - 1][Current->pos.x +1]; // Top Right
			Node* n4 = &grid[Current->pos.y][Current->pos.x - 1]; // Middle Left
			Node* n5 = &grid[Current->pos.y][Current->pos.x + 1]; // Middle Right
			Node* n6 = &grid[Current->pos.y + 1][Current->pos.x - 1]; // Bottom Left
			Node* n7 = &grid[Current->pos.y + 1][Current->pos.x]; // Bottom Middle
			Node* n8 = &grid[Current->pos.y + 1][Current->pos.x + 1]; // Bottom Right

			Node* neighbors[8] = { n1,n2,n3,n4,n5,n6,n7,n8 };

			for (Node*& node : neighbors)
			{
				node->SetCosts(start, { Current->pos.x,Current->pos.y }, dest);

				if (!node->traversable || IsIn(closedList, node)) continue;

				if (!IsIn(openList, node))
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