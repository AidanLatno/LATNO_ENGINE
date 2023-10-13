#pragma once
#include <iostream>
#include <vector>
#include "DeveloperLog.h"

namespace Latno 
{
    /*
    * Class Name: Behavior
    * Usage: Provide functionality to game objects, such as tags, update and start methods, and 
    *
    * Variables:
    *   doesLogOnNonOverload
    *       - When set to true, the Start and Update methods will log to the EngineLog when they are called before being overloaded.
    *   tagList
    *       - Contains a list of all tags currently assign to the instance.
    *   id
    *       - Number assigned to Behavior to identify it from the BehaviorList.
    *   
    * Methods:
    *   AddTag(string TagToAdd)
    *       - Adds a tag to the tagList.
    *   RemoveTag(string TagToRemove)
    *       - Removes a tag from the tagList
    *   clearTags()
    *       - Clears the tagList.
    *   IfHasTag(string Tag)
    *       - Checks for the provided tag within the tagList.
    *   GetTagList()
    *       - Returns the tagList.
    *   GetID()
    *       - Returns the ID.
    *   SetID(int value)
    *       - Sets the ID to value only if it hasn't been set yet, meaning it is one time use.
    * 
    * Virtual Methods:
    *   Start:
    *       - Gets called when the application firsts loads. Meant to be overriden.
    *   Update:
    *       - Gets called every frame. Meant to be overriden.
    */
    class Behavior 
    {
        private:
            std::vector<std::string> tagList;
            int id;
        public:
            bool doesLogOnNonOverload = false;
            void AddTag(std::string TagToAdd);
            void RemoveTag(std::string TagToRemove);
            void ClearTags();
            bool IfHasTag(std::string Tag);
            std::vector<std::string> GetTagList();
            int GetID();
            void SetID(int value);
            
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

    // Contains a list of every instance of the behavior class created
    // which allows objects to have their Start and Update methods called automatically
    extern std::vector<Latno::Behavior*> BehaviorList;
}