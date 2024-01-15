#include "../declarations/Pathfinder.h"


// Has useful psuedo code and explainations
// https://www.youtube.com/watch?v=-L-WgKMFuhE

namespace Latno
{
	Node* SmallestInList(std::vector<Node*> list)
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

	float Distance(Coords pos1, Coords pos2)
	{
		float a = std::abs(pos1.x - pos2.x);
		float b = std::abs(pos1.y - pos2.y);
		return std::sqrt((a * a) + (b * b));
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

		for (int y = 0; y < grid.size(); y++)
		{
			for (int x = 0; x < grid[y].size(); x++)
			{
				grid[y][x] = Node(x, y);
			}
		}

		return FindPath(dest, actorRef->GetPos());
	}

	std::vector<Coords> Pathfinder::FindPath(Coords dest, Coords start)
	{
		Node* Current;
		std::vector<Node*> openList, closedList;
		openList.push_back(&grid[start.y][start.x]); // Add start node to open

		int count = 0;

		while (true)
		{
			count++;
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

			// Trace back the path when the destination is met
			if (Current == &grid[dest.y][dest.x] || count > 1000)
			{
				std::vector<Coords> path;

				for (Node* i = Current; i != nullptr; i = i->parentPtr)
				{
					path.push_back(i->pos);
				}

				if (Current != &grid[dest.y][dest.x]) {
					// If the destination was not reached, handle accordingly.
					// For example, return an empty path or indicate failure.
					return std::vector<Coords>();
				}

				std::reverse(path.begin(), path.end()); // Reverse to get the correct order
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

					if (!neighbor->traversable || IsIn(closedList, neighbor)) continue;

					// Calculate costs and check for shorter path
					double tentative_gCost = Current->gCost + Distance(Current->pos, neighbor->pos);
					if (tentative_gCost < neighbor->gCost)
					{
						neighbor->parentPtr = Current;
						neighbor->SetCosts(start, neighbor->pos, dest);

						if (!IsIn(openList, neighbor))
							openList.push_back(neighbor);
					}
				}
			}

		}
		return std::vector<Coords>();
	}



	Pathfinder::~Pathfinder()
	{

	}
};