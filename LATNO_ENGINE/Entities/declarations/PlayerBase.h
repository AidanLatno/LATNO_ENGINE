#pragma once

#include "../../Entities/declarations/AdvancedActor.h"

namespace Latno
{
    class PlayerBase : public AdvancedActor
    {
        using AdvancedActor::AdvancedActor;
        public:
            int score = 0;
            void ManageInput(Scene &Scene, double deltaTime);

    };
}