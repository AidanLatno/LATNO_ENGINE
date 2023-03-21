#pragma once
#include <iostream>
#include <vector>
#include "DeveloperLog.h"

namespace Latno 
{
    class Behavior 
    {
        public:
            bool doesLogOnNonOverload = false;
            void AddTag(std::string TagToAdd);
            void RemoveTag(std::string TagToRemove);
            bool IfHasTag(std::string Tag);
            int id;

            std::vector<std::string> tagVector;

            virtual void Start()
            {
                if (doesLogOnNonOverload)
                    DevLog::LOGLN("Start() METHOD CALLED ON NON OVERLOADED BEHAVIOR", "EngineLog");
            }
            virtual void Update(double deltaTime)
            {
                if (doesLogOnNonOverload)
                    DevLog::LOGLN("Update() METHOD CALLED ON NON OVERLOADED BEHAVIOR", "EngineLog");
            }
    };

    extern std::vector<Latno::Behavior*> BehaviorList;
}