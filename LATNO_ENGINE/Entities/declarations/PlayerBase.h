#pragma once

#include "../../Entities/declarations/AdvancedActor.h"

namespace Latno
{
    /*
    * Class Name: PlayerBase
    * Purpose: This class is meant for quick debugging and testing if you need a controllable actor quickly.
    * Parents: AdvancedActor -> Actor -> Component -> Behavior
    * 
    * Methods:
    *    ManageInput(Scene &Scene)
    *       - Takes WASD input and sets direction accordingly
    *       - Moves in direction and accounts for speed
    */
    class PlayerBase : public AdvancedActor
    {
        using AdvancedActor::AdvancedActor;
        public:
            void ManageInput(Scene &Scene);

            void Update() override;
    };
}