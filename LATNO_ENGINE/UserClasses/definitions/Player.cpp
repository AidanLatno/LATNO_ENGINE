#include "../declarations/Player.h"

using namespace Latno;

void Player::Input()
{
    preData = GetPos();

    if (InputManager::KeyPressed(KEY_A) && GetPos().x > 0)
    {
        direction = LEFT;
        std::cout << "\n\n\nLEFT\n\n\n";
        Movement();
    }

    if (InputManager::KeyPressed(KEY_D))
    {
        direction = RIGHT;
        std::cout << "\n\n\nRIGHT\n\n\n";
        Movement();
    }
    if (InputManager::KeyPressed(KEY_W))
    {
        direction = UP;
        std::cout << "\n\n\nUP\n\n\n";
        Movement();
    }

    if (InputManager::KeyPressed(KEY_S))
    {
        direction = DOWN;
        std::cout << "\n\n\nDOWN\n\n\n";
        Movement();
    }
    if (InputManager::KeyPressed(KEY_LEFT_SHIFT))
    {
        for (Actor* a : currentScene->actors)
        {
            if(a->IfHasTag(moverTag))
                a->speed = 1000;
        }

        for (Actor& a : currentScene->dynamicActors)
        {
            if (a.IfHasTag(moverTag))
                a.speed = 1000;
        }
    }
    if (InputManager::KeyReleased(KEY_LEFT_SHIFT))
    {
        for (Actor* a : currentScene->actors)
        {
            if (a->IfHasTag(moverTag))
                a->speed = 200;
        }

        for (Actor& a : currentScene->dynamicActors)
        {
            if (a.IfHasTag(moverTag))
                a.speed = 200;
        }
    }
}

void Player::Movement()
{
	for (Actor* a : currentScene->actors)
	{
		if (a->IfHasTag(moverTag))
		{
            a->preData = a->GetPos();
            a->SetPos(a->GetPos() + (direction * (a->speed * GLOBAL_DELTA_TIME))*-1);
		}
	}

    for (Actor& a : currentScene->dynamicActors)
    {
        if (a.IfHasTag(moverTag))
        {
            a.preData = a.GetPos();
            a.SetPos(a.GetPos() + (direction * (a.speed * GLOBAL_DELTA_TIME))*-1);
        }
    }
}