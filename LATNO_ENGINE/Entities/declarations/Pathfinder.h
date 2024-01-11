#pragma once

#include "PlayerBase.h"
#include "../../engine/declarations/Node.h"


namespace Latno
{
    class Pathfinder
    {
    private:
        
    
    public:
        AdvancedActor* actorRef;
        std::vector<Coords> path;

        std::vector<std::vector<Node>> grid;

        std::vector<Coords> GetPath(Coords dest);
        std::vector<Coords> FindPath(Coords dest, Coords current);

        Node SetCosts(Coords start, Coords pos, Coords dest);
        
        ~Pathfinder();



    };
}