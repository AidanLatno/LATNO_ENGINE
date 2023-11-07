#pragma once

#include "../../Entities/declarations/AdvancedActor.h"

namespace Latno
{
    class PlayerBase : public AdvancedActor
    {
        using AdvancedActor::AdvancedActor;
        public:
            void ManageInput(Scene &Scene);

            void Update() override;
    };
}