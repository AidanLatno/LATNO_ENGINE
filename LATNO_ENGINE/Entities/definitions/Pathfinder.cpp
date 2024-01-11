#include "../declarations/Pathfinder.h"


// Has useful psuedo code and explainations
// https://www.youtube.com/watch?v=-L-WgKMFuhE

namespace Latno
{

	std::vector<Coords> Pathfinder::GetPath(Coords dest)
	{
		grid.resize(actorRef->currentScene->sizeY, std::vector<Node>(actorRef->currentScene->sizeX));

		std::vector<Coords> THEpath = FindPath(dest, actorRef->GetPos());
		path.clear();
		return THEpath;
	}

	std::vector<Coords> Pathfinder::FindPath(Coords dest, Coords current)
	{
		int curX = current.x;
		int curY = current.y;


		// STATIC CASTTT ONNN TOPPP 
		Coords node1 = { static_cast<float>(curX - 1), static_cast<float>(curY + 1) }; // top left
		Coords node2 = { static_cast<float>(curX + 0), static_cast<float>(curY + 1) }; // top mid
		Coords node3 = { static_cast<float>(curX + 1), static_cast<float>(curY + 1) }; // top right
		Coords node4 = { static_cast<float>(curX + 1), static_cast<float>(curY + 0) }; // right
		Coords node5 = { static_cast<float>(curX + 1), static_cast<float>(curY - 1) }; // bottom right
		Coords node6 = { static_cast<float>(curX + 0), static_cast<float>(curY - 1) }; // bottom mid
		Coords node7 = { static_cast<float>(curX - 1), static_cast<float>(curY - 1) }; // bottom left
		Coords node8 = { static_cast<float>(curX - 1), static_cast<float>(curY + 0) }; // left

		Coords nodeArr[8] = { node1, node2, node3, node4, node5, node6, node7, node8 };



		if (actorRef->GetPos() == current) {
			grid[curX][curY].fCost = 0.0;
			grid[curX][curY].gCost = 0.0;
			grid[curX][curY].hCost = 0.0;
			grid[curX][curY].parentX = curX;
			grid[curX][curY].parentY = curY;
		}
		else if (current != dest)
		{
			std::vector<Coords> tempVec;
			for (Coords point : nodeArr)
			{

				int x = point.x;
				int y = point.y;
				if (x >= 0 && x < actorRef->currentScene->sizeY && y >= 0 && y < actorRef->currentScene->sizeY)
				{
					Node costs = SetCosts(actorRef->GetPos(), current, dest);

					grid[x][y] = costs;
					grid[x][y].parentX = curX;
					grid[x][y].parentY = curY;

					tempVec.push_back(point);
				}
			};

			double lowestFCost = DBL_MAX;
			Coords lowestFCostCoord;
			for (Coords j : tempVec)
			{
				if (grid[j.x][j.y].fCost < lowestFCost)
				{
					if (grid[j.x][j.y].open) {
						lowestFCost = grid[j.x][j.y].fCost;
						lowestFCostCoord = j;
					}
				}

			}
			path.push_back(lowestFCostCoord);
			FindPath(dest, lowestFCostCoord);

		}
		else if (current == dest)
		{
			std::cout << "REACHED DEST.";
		}
		else
			std::cout << "ERROR";
		return path;

	}

	Node Pathfinder::SetCosts(Coords start, Coords pos, Coords dest)
	{
		Node node;

		node.gCost = std::abs(pos.x - start.x) + std::abs(pos.y - start.y);
		node.hCost = std::sqrt(std::pow(dest.x - start.x, 2) + std::pow(dest.y - start.y, 2));
		node.fCost = node.gCost + node.hCost;

		return node;
	}
};