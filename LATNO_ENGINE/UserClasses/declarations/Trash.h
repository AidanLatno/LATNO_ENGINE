#pragma once

#include "../../engine/declarations/Engine.h"
// CUSTOM TEMPLATE CLASS
// NOT PART OF ENGINE

class Trash : public Latno_Entities::AdvancedActor
{
public:
    void Start() override
    {
        DevLog::LOGLN("Player Start Has been ran!", "MainLog");
        glfwSetMouseButtonCallback(this->currentScene.window, [](GLFWwindow* window, int button, int action, int mods) {
            if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {

            }
        });

    }
    void Update(double deltaTime) override
    {

    }
};