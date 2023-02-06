#pragma once
#include <iostream>
#include <vector>
#include "DeveloperLog.h"

namespace Latno 
{
    class Behavior 
    {
        public:
            virtual void Start() { /*DevLog::LOGLN("Start() METHOD CALLED ON NON OVERLOADED BEHAVIOR","MainLog");*/ }
            virtual void Update(double deltaTime) { DevLog::LOGLN("Update() METHOD CALLED ON NON OVERLOADED BEHAVIOR", "MainLog"); };
            void AddTag(std::string TagToAdd);
            void RemoveTag(std::string TagToRemove);
            bool IfHasTag(std::string Tag);
            int id;
            std::vector<std::string> TagVector;
    };

    extern std::vector<Latno::Behavior*> BehaviorList;
}