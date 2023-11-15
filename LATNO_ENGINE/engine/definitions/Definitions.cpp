#include "../declarations/Definitions.h"

double GLOBAL_DELTA_TIME = 0;

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    // these three lines were default at event.c code
    Slot* slot = static_cast<Slot*>(glfwGetWindowUserPointer(window));
    printf("%08x to %i at %0.3f: Cursor position: %f %f\n",
        counter++, slot->number, glfwGetTime(), xpos, ypos);

    // these code copied from "cursorPosCallback" default optix sample function, commented above

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        std::cout << "LEFT CLICK";
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
    {
        std::cout << "RIGHT CLICK";
    }
}