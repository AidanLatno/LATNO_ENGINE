#include "../declarations/Pathfinder.h"

#include <queue>
#include <cmath>
#include <algorithm>
#include <set>

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
        std::vector<Coords> path;
        std::vector<Node*> nodes = FindPath(grid.getNode(actorRef->GetPos().x, actorRef->GetPos().y), grid.getNode(dest.x, dest.y));
        for (Node* n : nodes)
        {
            path.push_back({ static_cast<float>(n->x),static_cast<float>(n->y) });
        }

		return path;
	}

    std::vector<Node*> Pathfinder::FindPath(Node* startNode, Node* endNode) {
        std::priority_queue<Node*, std::vector<Node*>, NodeComparator> openSet;
        std::set<Node*> openSetTracker; // Track nodes in openSet
        std::vector<Node*> closedSet;
        std::vector<Node*> path;

        startNode->gCost = 0;
        startNode->calculateCosts(endNode); // Initialize start node costs
        openSet.push(startNode);
        openSetTracker.insert(startNode);

        while (!openSet.empty()) {
            Node* currentNode = openSet.top();
            openSet.pop();
            openSetTracker.erase(currentNode);

            if (currentNode == endNode) {
                while (currentNode != nullptr) {
                    path.push_back(currentNode);
                    currentNode = currentNode->parent;
                }
                std::reverse(path.begin(), path.end());
                return path;
            }

            closedSet.push_back(currentNode);

            std::vector<Node*> neighbors = grid.getNeighbors(currentNode);

            for (Node* neighbor : neighbors) {
                if (!neighbor->isTraversable || std::find(closedSet.begin(), closedSet.end(), neighbor) != closedSet.end()) {
                    continue; // Ignore non-traversable or already evaluated neighbors
                }

                int newGCost = currentNode->gCost + 1; // Assuming a uniform cost for simplicity
                if (newGCost < neighbor->gCost) {
                    neighbor->gCost = newGCost;
                    neighbor->calculateCosts(endNode);
                    neighbor->parent = currentNode;

                    if (openSetTracker.find(neighbor) == openSetTracker.end()) {
                        openSet.push(neighbor);
                        openSetTracker.insert(neighbor);
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