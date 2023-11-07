#pragma once

#include "Definitions.h"

namespace Latno 
{
    /*
    * Class Name: Component
    * Parent: Behavior
    * Purpose: A component is a object that executes some type of behavior using the Update and Start methods,
    *          such as a game object moving every frame or a logic component to attach to an object that does
    *          some kind of operation. All components are automatically added to the behaviorList as soon as
    *          they are initialized.
    * 
    * Constructor: Adds "this" to the behaviorList, allowing its behaviors to be called automatically with no
    *              extra initialization needed. Also assigns a unique ID exclusive to this instance.
    * Destructor: Automatically removes this Component from the behaviorList
    */
    class Component : public Latno::Behavior
    {
        public:

            Component();
            ~Component();
            
            void Start() override
            {
                if(doesLogOnNonOverload)
                    DevLog::LOGLN("Start() METHOD CALLED ON NON OVERLOADED BEHAVIOR", "EngineLog");
            }
            void Update() override
            {
                if(doesLogOnNonOverload)
                    DevLog::LOGLN("Update() METHOD CALLED ON NON OVERLOADED BEHAVIOR", "EngineLog");
            }
    };
    
}
