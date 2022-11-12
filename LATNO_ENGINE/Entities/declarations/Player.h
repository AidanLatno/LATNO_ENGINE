#pragma once

#include "../../engine/declarations/Menu.h"

namespace Latno_Entities 
{
    class Player: public AdvancedActor
    {
        using AdvancedActor::AdvancedActor;
        public:
            int Points = 0;
            Menu* MainMenu;
            void Move(Scene &Scene);
    };
}