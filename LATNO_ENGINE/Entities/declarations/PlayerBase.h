#pragma once

#include "../../engine/declarations/Menu.h"

namespace Latno_Entities
{
    class PlayerBase : public AdvancedActor
    {
        using AdvancedActor::AdvancedActor;
        public:
            int Points = 0;
            Menu* MainMenu;
            void Move(Scene Scene);
            void Move();
            virtual void MenuFunctionality() { DevLog::LOGLN("[WARNING] PlayerBase Menu Function called but not overridden","MainLog"); };

    };
}