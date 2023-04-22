#pragma once
#include "../declarations/PlayerBase.h"
namespace Latno_Entities 
{
    void PlayerBase::Move(Scene &Scene)
    {
        preData = GetPos();
        if (glfwGetKey(Scene.window, GLFW_KEY_W) == GLFW_PRESS && GetPos().y > 0)
        {
            direction = UP;
            MoveForward(Scene);
        }
        if (glfwGetKey(Scene.window, GLFW_KEY_A) == GLFW_PRESS && GetPos().x > 0)
        {
            direction = LEFT;
            MoveForward(Scene);
        }
        if (glfwGetKey(Scene.window, GLFW_KEY_S) == GLFW_PRESS && GetPos().y < Scene.GetSize().y - 1)
        {
            direction = DOWN;
            MoveForward(Scene);
        }
        if (glfwGetKey(Scene.window, GLFW_KEY_D) == GLFW_PRESS && GetPos().x < Scene.GetSize().x - 1)
        {
            direction = RIGHT;
            MoveForward(Scene);
        }
    }
}