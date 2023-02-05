#pragma once

#include "Definitions.h"

namespace Latno 
{
    class Component : public Latno::Behavior
    {
        public:
            std::vector<std::string> tags;
            
            Component();

            bool HasTag(std::string tag);
            
            void Start() override
            {
                DevLog::LOGLN("Start() METHOD CALLED ON NON OVERLOADED BEHAVIOR", "MainLog");
            }
            void Update(double deltaTime) override
            {
                DevLog::LOGLN("Update() METHOD CALLED ON NON OVERLOADED BEHAVIOR", "MainLog");
            }
            
    };
    
}
