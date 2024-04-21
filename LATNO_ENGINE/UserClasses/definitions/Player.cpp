#include "../declarations/Player.h"

using namespace Latno;

void Player::Input()
{
    preData = GetPos();

    if (InputManager::KeyPressed(KEY_A) && GetPos().x > 0)
    {
        direction = LEFT;
        Movement();
    }

    if (InputManager::KeyPressed(KEY_D))
    {
        direction = RIGHT;
        Movement();
    }
    if (InputManager::KeyPressed(KEY_W))
    {
        direction = UP;
        Movement();
    }

    if (InputManager::KeyPressed(KEY_S))
    {
        direction = DOWN;
        Movement();
    }
    if (InputManager::KeyPressed(KEY_LEFT_SHIFT))
    {
        speed = 1000;
    }
    if (InputManager::KeyReleased(KEY_LEFT_SHIFT))
    {
        speed = 200;
    }
}

void Player::Movement()
{
	for (Actor* a : currentScene->actors)
	{
		if (a->IfHasTag(moverTag))
		{
            a->preData = a->GetPos();
            a->SetPos(a->GetPos() + a->direction * (a->speed * GLOBAL_DELTA_TIME));
		}
	}

    for (Actor& a : currentScene->dynamicActors)
    {
        if (a.IfHasTag(moverTag))
        {
            a.preData = a.GetPos();
            a.SetPos(a.GetPos() + a.direction * (a.speed * GLOBAL_DELTA_TIME));
        }
    }
}