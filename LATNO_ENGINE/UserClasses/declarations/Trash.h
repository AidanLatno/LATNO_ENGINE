#pragma once
#include <iostream>;
#include "../../engine/declarations/Engine.h"
// CUSTOM TEMPLATE CLASS
// NOT PART OF ENGINE

namespace Latno_Entities {

    class Trash : public Latno_Entities::AdvancedActor
    {
        using AdvancedActor::AdvancedActor;
    public:
        void Start() override
        {
            DevLog::LOGLN("Player Start Has been ran!", "MainLog");
        }

        // Register the callback function
        void Update(double deltaTime) override
        {
            SetPos({ GetPos().x, GetPos().y - 1 });

          
        }
    };
}