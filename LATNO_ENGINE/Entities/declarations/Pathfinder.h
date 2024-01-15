#pragma once

#include "PlayerBase.h"
#include "../../engine/declarations/Grid.h"


namespace Latno
{
    class Pathfinder
    {
    private:
        
    
    public:
        AdvancedActor* actorRef;

        Grid grid;

        std::vector<Coords> GetPath(Coords dest);
        std::vector<Node*> FindPath(Node* startNode, Node* endNode);

        Node SetCosts(Coords start, Coords pos, Coords dest);

        int counter = 1;
        
        ~Pathfinder();



    };
}