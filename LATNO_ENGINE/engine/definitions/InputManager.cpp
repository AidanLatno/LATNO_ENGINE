#include "../declarations/InputManager.h"

bool InputManager::KeyPressed(Key key)
{
	return glfwGetKey(window, key) == GLFW_PRESS;
}

bool InputManager::KeyReleased(Key key)
{
	return glfwGetKey(window, key) == GLFW_RELEASE;
}