#pragma once

#include "Coords.h"

namespace Latno_Entities
{
    struct Route
    {
        Coords Start_Pos;
        Coords End_Pos;
        Coords *CurrentChase = &End_Pos;

        void Swap();
    };   
}