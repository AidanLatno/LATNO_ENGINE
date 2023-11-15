#pragma once
#include "../declarations/PlayerBase.h"
namespace Latno
{
    void PlayerBase::ManageInput(Scene &Scene)
    {
        preData = GetPos();
       
        if (glfwGetKey(Scene.window, GLFW_KEY_A) == GLFW_PRESS && GetPos().x > 0)
        {
            direction = LEFT;
            MoveForward(Scene);
        }
      
        if (glfwGetKey(Scene.window, GLFW_KEY_D) == GLFW_PRESS && GetPos().x < Scene.GetSize().x)
        {
			direction = RIGHT;
			MoveForward(Scene);
        }
        if (glfwGetKey(Scene.window, GLFW_KEY_W) == GLFW_PRESS && GetPos().y < Scene.GetSize().y)
        {
            direction = UP;
            MoveForward(Scene);
        }

        if (glfwGetKey(Scene.window, GLFW_KEY_S) == GLFW_PRESS && GetPos().y > 0)
        {
            direction = DOWN;
            MoveForward(Scene);
        }
        if (glfwGetKey(Scene.window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        {
            speed = 1000;
        }
        if (glfwGetKey(Scene.window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
        {
            speed = 200;
        }
    }

    void PlayerBase::Update()
    {
        ManageInput(*currentScene);
    }
}