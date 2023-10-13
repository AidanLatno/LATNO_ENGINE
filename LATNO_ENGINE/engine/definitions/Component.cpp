#include "../declarations/Component.h"

namespace Latno
{
    Component::Component()
    {
        if (Latno::BehaviorList.size() > 0) SetID(Latno::BehaviorList[Latno::BehaviorList.size() - 1]->GetID() + 1);
        else SetID(0);
        Latno::BehaviorList.push_back(this);
    }

    Component::~Component()
    {
        for (int i = 0; i < BehaviorList.size(); i++)
        {
            if (BehaviorList[i] == this)
                BehaviorList.erase(BehaviorList.begin() + i);
        }
    }
}           
