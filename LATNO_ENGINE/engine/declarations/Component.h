#pragma once

#include "Behavior.h"

namespace Latno 
{
    class Component 
    {
        public:
            const Behavior behavior;
            Component(Behavior _behavior);
    };
}