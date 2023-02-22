#pragma once
#include "../declarations/PlayerBase.h"
namespace Latno_Entities 
{
    void PlayerBase::Move(Scene &Scene)
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
                MoveForward(Scene);
            }
            else if (Input == 'a' && position.x > 0)
            {
                direction = LEFT;
                MoveForward(Scene);
            }
            else if (Input == 's' && position.y < Scene.GetSize().y - 1)
            {
                direction = DOWN;
                MoveForward(Scene);
            }
            else if (Input == 'd' && position.x < Scene.GetSize().x - 1)
            {
                direction = RIGHT;
                MoveForward(Scene);
            }
            else if(Input == '\t')
            {
                MenuFunctionality();
            }
        }
        else
            usleep(100000 * 1);
    }

    // MEANT TO BE OVERRIDDEN
    void PlayerBase::MenuFunctionality()
    {
        int MenuInput = MainMenu->OpenMenu("MAIN MENU", true);
        switch (MenuInput)
        {
        case 0:

            break;
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        default:
            std::cout << "\033[31mERROR";
            return;
        }
    }
}