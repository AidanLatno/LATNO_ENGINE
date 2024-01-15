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
	
		grid.resize(actorRef->currentScene->sizeY, std::vector<Node>(actorRef->currentScene->sizeX));


		std::vector<Coords> THEpath = FindPath(dest, actorRef->GetPos());
		path.clear();
		return THEpath;
	}

	

	std::vector<Coords> Pathfinder::FindPath(Coords dest, Coords current)
	{
		Node* Current;
		std::vector<Node*> openList, closedList;
		openList.push_back(&grid[start.y][start.x]); // Add start node to open


		std::cout << "it iterates \n";
		std::cout << counter++;
	
		if (curX == 0)
			return path;

		// STATIC CASTTT ONNN TOPPP 
		Coords node1 = { curX - 1, curY + 1 }; // top left
		Coords node2 = { curX + 0, curY + 1 }; // top mid
		Coords node3 = { curX + 1, curY + 1 }; // top right
		Coords node4 = { curX + 1, curY + 0 }; // right
		Coords node5 = { curX + 1, curY - 1 }; // bottom right
		Coords node6 = { curX + 0, curY - 1 }; // bottom mid
		Coords node7 = { curX - 1, curY - 1 }; // bottom left
		Coords node8 = { curX - 1, curY + 0 }; // left

		Coords nodeArr[8] = { node1, node2, node3, node4, node5, node6, node7, node8 };



		if (actorPos == current) {
			grid[curY][curX].fCost = 0.0;
			grid[curY][curX].gCost = 0.0;
			grid[curY][curX].hCost = 0.0;
		}
		if (current != dest)
		{
			std::vector<Coords> tempVec;
			for (Coords point : nodeArr)
			{

			// Erase current from OPEN
			auto it = std::find(openList.begin(), openList.end(), Current);
			if (it != openList.end()) { openList.erase(it); }

			closedList.push_back(Current);

				int x = point.x;
				int y = point.y;
				if (x >= 0 && x < actorRef->currentScene->sizeX && y >= 0 && y < actorRef->currentScene->sizeY)

				{
					Node costs = SetCosts(actorPos, point, dest);

					grid[y][x] = costs;
					grid[y][x].parentX = curX;
					grid[y][x].parentY = curY;

					tempVec.push_back(point);
				}
			};

				for (Node* i = Current; i != nullptr; i = i->parentPtr)
				{
					path.push_back(i->pos);
				}

				if (Current != &grid[dest.y][dest.x]) {
					// If the destination was not reached, handle accordingly.
					// For example, return an empty path or indicate failure.
					return std::vector<Coords>();
				}

			int x = lowestFCostCoord.x;
			int y = lowestFCostCoord.y;

			grid[y][x].open = false;
			path.push_back(lowestFCostCoord);
			FindPath(dest, lowestFCostCoord);
		}
		
		else if (current == dest)
		{
			std::cout << "REACHED DEST.";
			return path;
		}
		else
			std::cout << "ERROR";

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