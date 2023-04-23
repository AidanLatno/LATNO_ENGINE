#pragma once
#include "../declarations/PlayerBase.h"
namespace Latno_Entities 
{
    void PlayerBase::ManageInput(Scene &Scene)
    {
        preData = GetPos();
       
        if (glfwGetKey(Scene.window, GLFW_KEY_A) == GLFW_PRESS && GetPos().x > 0)
        {
            direction = LEFT;
            MoveForward(Scene);
        }
      
        if (glfwGetKey(Scene.window, GLFW_KEY_D) == GLFW_PRESS && GetPos().x < Scene.GetSize().x - 1)
        {
            direction = RIGHT;
            MoveForward(Scene);
        }
    }
}