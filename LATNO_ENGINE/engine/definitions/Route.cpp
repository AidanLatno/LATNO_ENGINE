#pragma once

#include "../declarations/Route.h"

namespace Latno
{
    void Route::Swap()
    {
        if(CurrentChase == &End_Pos)
            CurrentChase = &Start_Pos;
        else
            CurrentChase = &End_Pos;
    }   
}
