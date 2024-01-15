#pragma once
#include "Node.h"


namespace Latno
{
    class Grid {
        // Assuming a predefined grid size, but this could be made dynamic
        static const int WIDTH = WINDOW_LENGTH;
        static const int HEIGHT = WINDOW_HEIGHT;
        Node* grid[HEIGHT][WIDTH];

    public:
        Grid() {
            for (int y = 0; y < HEIGHT; ++y) {
                for (int x = 0; x < WIDTH; ++x) {
                    grid[y][x] = new Node(x, y);
                }
            }
        }

        ~Grid() {
            for (int y = 0; y < HEIGHT; ++y) {
                for (int x = 0; x < WIDTH; ++x) {
                    delete grid[y][x];
                }
            }
        }

        Node* getNode(int x, int y) {
            if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
                return grid[y][x];
            }
            return nullptr;
        }

        std::vector<Node*> getNeighbors(Node* node) {
            std::vector<Node*> neighbors;

            // Up
            if (node->y > 0 && grid[node->y - 1][node->x]->isTraversable)
                neighbors.push_back(grid[node->y - 1][node->x]);

            // Down
            if (node->y < HEIGHT - 1 && grid[node->y + 1][node->x]->isTraversable)
                neighbors.push_back(grid[node->y + 1][node->x]);

            // Left
            if (node->x > 0 && grid[node->y][node->x - 1]->isTraversable)
                neighbors.push_back(grid[node->y][node->x - 1]);

            // Right
            if (node->x < WIDTH - 1 && grid[node->y][node->x + 1]->isTraversable)
                neighbors.push_back(grid[node->y][node->x + 1]);

            return neighbors;
        }
    };
}