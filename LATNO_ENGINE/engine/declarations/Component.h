#pragma once

#include "Definitions.h"

namespace Latno 
{
    class Component : public Latno::Behavior
    {
        public:
            bool doesLogOnNonOverload = false;
            
            Component();
            ~Component();

            
            void Start() override
            {
                if(doesLogOnNonOverload)
                    DevLog::LOGLN("Start() METHOD CALLED ON NON OVERLOADED BEHAVIOR", "EngineLog");
            }
            void Update(double deltaTime) override
            {
                if(doesLogOnNonOverload)
                    DevLog::LOGLN("Update() METHOD CALLED ON NON OVERLOADED BEHAVIOR", "EngineLog");
            }
    };
    
}
