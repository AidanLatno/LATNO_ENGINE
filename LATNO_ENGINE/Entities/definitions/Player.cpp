#pragma once
#include "../declarations/Player.h"
namespace Latno_Entities 
{
    void Player::Move(Scene &Scene)
    {
        char Input;
        int MenuInput;
        preData = position;
        Input = _getch();
        if(Input == 'w' && position.y > 0)
        {
            direction = UP;
            MoveFoward(Scene);
        }
        else if(Input == 'a' && position.x > 0)
        {
            direction = LEFT;
            MoveFoward(Scene);
        }
        else if(Input == 's' && position.y < Scene.GetSize().y - 1)
        {
            direction = DOWN;
            MoveFoward(Scene);
        }
        else if(Input == 'd' && position.x < Scene.GetSize().x - 1)
        {
            direction = RIGHT;
            MoveFoward(Scene);
        }
        else if(Input == 'f')
        {
            AdvancedActor TempDynamicActor(position.x,position.y,ToChar("void"),"BULLET");
            TempDynamicActor.direction = direction;
                
            Scene.AddDynamicActor(TempDynamicActor);
        }
        /* Code yourself to fit your game (Main menu functionality)
        else if(Input == '\t')
        {
            MenuInput = MainMenu->OpenMenu("MAIN MENU");
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
        */
        if (Scene.dynamicActors.size() > 0)
        {
            for (int i = 0; i < Scene.dynamicActors.size(); i++)
            {
                if (Scene.dynamicActors[i].position.y <= 0 || Scene.dynamicActors[i].position.y >= Scene.GetSize().x - 1 || Scene.dynamicActors[i].position.x <= 0 || Scene.dynamicActors[i].position.x >= Scene.GetSize().y - 1)
                {
                    Scene.DestroyDynamicActor(i);
                    continue;
                }

                Scene.dynamicActors[i].position += Scene.dynamicActors[i].direction;
            }
        }
    }
}