#include "../declarations/TopDownPlayer.h"

using namespace Latno;

void TopDownPlayer::Input()
{
    preData = GetPos();

    if (InputManager::KeyPressed(KEY_A))
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

void TopDownPlayer::Movement()
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

void TopDownPlayer::Update()
{
    {
        std::cout << direction.x << std::endl;
        if (direction.x < 0 || InputManager::KeyPressed(KEY_A))
            Animate(0.1f, spriteListL);
        else
            Animate(0.1f, spriteList);

        Input();
    }
}