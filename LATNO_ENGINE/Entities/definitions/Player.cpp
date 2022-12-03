#pragma once
#include "../declarations/Player.h"
namespace Latno_Entities 
{
    void Player::Move(Scene &Scene)
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
            /* Code yourself to fit your game (Main menu functionality)*/
            else if(Input == '\t')
            {
                MenuInput = MainMenu->OpenMenu("MAIN MENU",true);
                switch(MenuInput)
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
        else
            usleep(100000);
    }
}