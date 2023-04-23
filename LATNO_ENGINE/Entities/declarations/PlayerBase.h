#pragma once

#include "../../shapes/declarations/Triangle.h"

namespace Latno_Entities
{
    class PlayerBase : public AdvancedActor
    {
        using AdvancedActor::AdvancedActor;
        public:
            int Points = 0;
            void ManageInput(Scene &Scene, float deltaTime);

    };
}