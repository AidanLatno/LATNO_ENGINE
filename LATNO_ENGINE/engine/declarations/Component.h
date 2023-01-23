#pragma once

#include "Definitions.h"

namespace Latno 
{
    class Component : public Latno::Behavior
    {
        public:
            Component();
            void Start() override
            {
                DevLog::LOGLN("Start() METHOD CALLED ON NON OVERLOADED BEHAVIOR", "MainLog");
            }
            void Update() override
            {
                DevLog::LOGLN("Update() METHOD CALLED ON NON OVERLOADED BEHAVIOR", "MainLog");
            }
            
    };
    
}
