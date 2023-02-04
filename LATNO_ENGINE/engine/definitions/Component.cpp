#include "../declarations/Component.h"

namespace Latno
{
    Component::Component()
    {
        if (Latno::BehaviorList.size() > 0) id = Latno::BehaviorList[Latno::BehaviorList.size() - 1]->id + 1;
        else id = 0;
        Latno::BehaviorList.push_back(this);
        DevLog::LOGLN("New component made with ID of " + std::to_string(id),"MainLog");
    }
    Component::~Component()
    {
        for (int i = 0; i < Latno::BehaviorList.size(); i++)
        {
            if (Latno::BehaviorList[i]->id == id)
            {
                Latno::BehaviorList.erase(Latno::BehaviorList.begin() + i);
                break;
            }
        }
    }
} 
