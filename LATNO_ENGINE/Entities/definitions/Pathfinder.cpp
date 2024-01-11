#include "../declarations/Pathfinder.h"


// Has useful psuedo code and explainations
// https://www.youtube.com/watch?v=-L-WgKMFuhE

namespace Latno
{

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

	std::vector<Coords> Pathfinder::FindPath(Coords dest, Coords current)
	{
		int curX = current.x;
		int curY = current.y;
		Coords actorPos = actorRef->GetPos();

		std::cout << "it iterates\n";
		// DELETE LATER
		if (path.size() > 500) return path;

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



		if (actorPos == current) {
			grid[curY][curX].fCost = 0.0;
			grid[curY][curX].gCost = 0.0;
			grid[curY][curX].hCost = 0.0;
			grid[curY][curX].parentX = curX;
			grid[curY][curX].parentY = curY;
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
				if (x >= 0 && x < actorRef->currentScene->sizeY && y >= 0 && y < actorRef->currentScene->sizeY)
				{
					Node costs = SetCosts(actorPos, current, dest);

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
				if (grid[(int)j.y][(int)j.x].fCost < lowestFCost)
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
		}
		else
			std::cout << "ERROR";

		

		return path;

	}

	Node Pathfinder::SetCosts(Coords start, Coords pos, Coords dest)
	{
		Node node;

		node.gCost = std::abs(pos.x - start.x) + std::abs(pos.y - start.y);
		node.hCost = std::sqrt(std::pow(dest.x - pos.x, 2) + std::pow(dest.y - pos.y, 2));
		node.fCost = node.gCost + node.hCost;

		return node;
	}

	Pathfinder::~Pathfinder()
	{

	}
};