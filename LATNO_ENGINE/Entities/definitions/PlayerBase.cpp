#pragma once
#include "../declarations/PlayerBase.h"
namespace Latno
{
    void PlayerBase::ManageInput(Scene &Scene)
    {
        preData = GetPos();
       
        if (glfwGetKey(Scene.window, GLFW_KEY_A) == GLFW_PRESS && GetPos().x > 160)
        {
            direction = LEFT;
            MoveForward(Scene);
        }
      
        if (glfwGetKey(Scene.window, GLFW_KEY_D) == GLFW_PRESS && GetPos().x < Scene.GetSize().x - 75)
        {
			direction = RIGHT;
			MoveForward(Scene);
        }
        if (glfwGetKey(Scene.window, GLFW_KEY_W) == GLFW_PRESS && GetPos().y < Scene.GetSize().y - 100)
        {
            direction = UP;
            MoveForward(Scene);
        }

        if (glfwGetKey(Scene.window, GLFW_KEY_S) == GLFW_PRESS && GetPos().y > 20)
        {
            direction = DOWN;
            MoveForward(Scene);
        }
        if (glfwGetKey(Scene.window, GLFW_KEY_SPACE) == GLFW_PRESS)
        {
            score += 20;
        }
    }
}