#pragma once
#include "../declarations/PlayerBase.h"
namespace Latno_Entities 
{
    void PlayerBase::Move(Scene Scene)
    {
        char Input;
        int MenuInput;
        preData = position;
        if (_kbhit())
        {
            Input = _getch();
            if (Input == 'w' && position.y > 0)
            {
                direction = UP;
                MoveFoward(Scene);
            }
            else if (Input == 'a' && position.x > 0)
            {
                direction = LEFT;
                MoveFoward(Scene);
            }
            else if (Input == 's' && position.y < Scene.GetSize().y - 1)
            {
                direction = DOWN;
                MoveFoward(Scene);
            }
            else if (Input == 'd' && position.x < Scene.GetSize().x - 1)
            {
                direction = RIGHT;
                MoveFoward(Scene);
            }
            else if(Input == '\t')
            {
                MenuFunctionality();
            }
        }
        else
            usleep(100000);
    }
    void PlayerBase::Move()
    {
        char Input;
        int MenuInput;
        preData = position;
        if (_kbhit())
        {
            Input = _getch();
            if (Input == 'w' && position.y > 0)
            {
                direction = UP;
                MoveFoward();
            }
            else if (Input == 'a' && position.x > 0)
            {
                direction = LEFT;
                MoveFoward();
            }
            else if (Input == 's' && position.y < currentScene->GetSize().y - 1)
            {
                direction = DOWN;
                MoveFoward();
            }
            else if (Input == 'd' && position.x < currentScene->GetSize().x - 1)
            {
                direction = RIGHT;
                MoveFoward();
            }
            else if (Input == '\t')
            {
                MenuFunctionality();
            }
        }
        else
            usleep(100000);
    }
}