#include "../declarations/Pathfinder.h"


// Has useful psuedo code and explainations
// https://www.youtube.com/watch?v=-L-WgKMFuhE

namespace Latno
{

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
		int curX = current.x;
		int curY = current.y;
		Coords actorPos = actorRef->GetPos();


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

				if (point.x < 0 || point.x >= grid[0].size() || point.y < 0 || point.y >= grid.size()) break;
				
				int blahY = (int)point.y;
				int blahX = (int)point.x;
				Node qwerty = grid[blahY][blahX];
				if (qwerty.open == false) break;


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

			double lowestFCost = DBL_MAX;
			Coords lowestFCostCoord;
			for (Coords j : tempVec)
			{
				float _fCost = grid[(int)j.y][(int)j.x].fCost;
				if (_fCost < lowestFCost)
				{
					if (grid[(int)j.y][(int)j.x].open) {
						lowestFCost = grid[(int)j.y][(int)j.x].fCost;
						lowestFCostCoord = j;
					}
				}

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

		

		return path;

	}

	Node Pathfinder::SetCosts(Coords start, Coords pos, Coords dest)
	{
		Node node;

		// Calculate gCost. For diagonal movement, use a different cost.
		float diagonalCost = std::sqrt(2); // Cost for diagonal movement
		int dx = std::abs(pos.x - start.x);
		int dy = std::abs(pos.y - start.y);
		int minD = std::min(dx, dy);
		int straightD = dx + dy;
		node.gCost = minD * diagonalCost + (straightD - 2 * minD);

		// Use Euclidean distance for hCost (heuristic cost).
		node.hCost = std::sqrt(std::pow(dest.x - pos.x, 2) + std::pow(dest.y - pos.y, 2)); // Euclidean distance to destination

		node.fCost = node.gCost + node.hCost; // Total cost

		return node;
	}

	Pathfinder::~Pathfinder()
	{

	}
};