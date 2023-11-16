#pragma once
#include "../declarations/PlayerBase.h"
namespace Latno
{
    void PlayerBase::ManageInput(Scene &Scene)
    {
        preData = GetPos();
       
        if (InputManager::KeyPressed(KEY_A) && GetPos().x > 0)
        {
            direction = LEFT;
            MoveForward(Scene);
        }
      
        if (InputManager::KeyPressed(KEY_D) && GetPos().x < Scene.GetSize().x)
        {
			direction = RIGHT;
			MoveForward(Scene);
        }
        if (InputManager::KeyPressed(KEY_W) && GetPos().y < Scene.GetSize().y)
        {
            direction = UP;
            MoveForward(Scene);
        }

        if (InputManager::KeyPressed(KEY_S) && GetPos().y > 0)
        {
            direction = DOWN;
            MoveForward(Scene);
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

    void PlayerBase::Update()
    {
        ManageInput(*currentScene);
    }
}