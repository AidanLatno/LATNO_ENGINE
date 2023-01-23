#pragma once
#include <iostream>
#include <vector>
#include "DeveloperLog.h"

namespace Latno 
{
    class Behavior 
    {
        public:
            virtual void Start() { DevLog::LOGLN("Start() METHOD CALLED ON NON OVERLOADED BEHAVIOR","MainLog"); }
            virtual void Update() { DevLog::LOGLN("Update() METHOD CALLED ON NON OVERLOADED BEHAVIOR", "MainLog"); };
            int id;
    };

    extern std::vector<Latno::Behavior*> BehaviorList;
}