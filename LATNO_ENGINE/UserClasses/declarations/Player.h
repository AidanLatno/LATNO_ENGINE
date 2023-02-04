#pragma once

#include "../../engine/declarations/Engine.h"

class Player : public PlayerBase
{
using PlayerBase::PlayerBase;
public:
    void Start() override
    {
        DevLog::LOGLN("Player start has been overridden!", "MainLog");
    }

    void Update() override
    {
        Move();
        DevLog::LOGLN("Player Update has been overridden!", "MainLog");
    }
};