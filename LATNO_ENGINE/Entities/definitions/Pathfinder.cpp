#include "../declarations/Pathfinder.h"

#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>

// Has useful psuedo code and explainations
// https://www.youtube.com/watch?v=-L-WgKMFuhE

namespace Latno
{
    class NodeComparator {
    public:
        bool operator()(const Node* lhs, const Node* rhs) const {
            return lhs->fCost > rhs->fCost;
        }
    };

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
        grid.~Grid();

        grid = *new Grid();

        std::vector<Coords> path;
        std::vector<Node*> nodes = FindPath(grid.getNode(actorRef->GetPos().x, actorRef->GetPos().y), grid.getNode(dest.x, dest.y));
        for (Node* n : nodes)
        {
            path.push_back({ static_cast<float>(n->x),static_cast<float>(n->y) });
        }

		return path;
	}

    std::vector<Node*> Pathfinder::FindPath(Node* startNode, Node* endNode) {
        std::set<std::pair<int, Node*>> openSet; // Pair of (cost, Node*)
        std::unordered_map<Node*, int> openSetTracker; // Tracks Node* and their gCost
        std::unordered_set<Node*> closedSet;
        std::vector<Node*> path;

        startNode->gCost = 0;
        startNode->calculateCosts(endNode);
        openSet.insert({ startNode->fCost, startNode });
        openSetTracker[startNode] = startNode->gCost;

        while (!openSet.empty()) {
            Node* currentNode = openSet.begin()->second;
            openSet.erase(openSet.begin());
            openSetTracker.erase(currentNode);

            if (currentNode == endNode) {
                while (currentNode != nullptr) {
                    path.push_back(currentNode);
                    currentNode = currentNode->parent;
                }
                std::reverse(path.begin(), path.end());
                return path;
            }

            closedSet.insert(currentNode);
            std::vector<Node*> neighbors = grid.getNeighbors(currentNode);

            for (Node* neighbor : neighbors) {
                if (!neighbor->isTraversable || closedSet.find(neighbor) != closedSet.end()) {
                    continue;
                }

                int newGCost = currentNode->gCost + 1;
                if (newGCost < neighbor->gCost) {
                    neighbor->gCost = newGCost;
                    neighbor->calculateCosts(endNode);
                    neighbor->parent = currentNode;

                    if (openSetTracker.find(neighbor) == openSetTracker.end() || openSetTracker[neighbor] > newGCost) {
                        openSet.erase({ neighbor->fCost, neighbor }); // Remove old entry if it exists
                        neighbor->fCost = newGCost + neighbor->hCost; // Update fCost
                        openSet.insert({ neighbor->fCost, neighbor }); // Insert updated node
                        openSetTracker[neighbor] = newGCost;
                    }
                }
            }
        }

        return std::vector<Node*>(); // If no path is found, return an empty path


    }

	

	Pathfinder::~Pathfinder()
	{

	}
};