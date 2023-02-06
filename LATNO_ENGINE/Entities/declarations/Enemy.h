#pragma once

#include "PlayerBase.h"

namespace Latno_Entities
{
    class Enemy : public AdvancedActor
    {
    using AdvancedActor::AdvancedActor;
    private:
        // 0 is up (y-1) 1 is down (y+1) 2 is left (x-1) 3 is right (x+1)
        bool isBlocked[4] = {0,0,0,0};
        int distanceX, distanceY, totalDistance, trueDistanceX, trueDistanceY;
    
    public:
        int moveChance[2] = {0,10}; // First Num is range, second is size  Ex
        void Chase(Scene &scene, Latno_Entities::Actor chaseActor);
        Coords **nodeValues;
        
        void Start() override
        {
            // Creates 2d Array of Coords with currentScene's dimensions
            nodeValues = new Coords* [currentScene->sizeY];

            for (int i = 0; i < currentScene->sizeY; ++i)
                nodeValues[i] = new Coords[currentScene->sizeX];


            // initializes array
            for (int y = 0; y < currentScene->sizeY; y++)
            {

                for (int x = 0; x < currentScene->sizeX; x++)
                {

                    nodeValues[y][x] = Coords(0,0);
                }
            }
        }

    };
}