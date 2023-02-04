#pragma once

#include "../../engine/declarations/Engine.h"

class Button : public AdvancedActor
{
using AdvancedActor::AdvancedActor;
public:
    void Start() override
    {
        DevLog::LOGLN("Player start has been overridden!", "MainLog");
    }

    void Update() override
    {
        DevLog::LOGLN("Player Update has been overridden!", "MainLog");
    }
};