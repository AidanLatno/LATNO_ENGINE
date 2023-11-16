#include "../declarations/InputManager.h"
namespace Latno
{
	GLFWwindow* InputManager::window = NULL;

	bool InputManager::KeyPressed(Key key)
	{
		return glfwGetKey(window, key) == GLFW_PRESS;
	}

	bool InputManager::KeyReleased(Key key)
	{
		return glfwGetKey(window, key) == GLFW_RELEASE;
	}
	Coords InputManager::GetMousePos()
	{
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return Coords(x, WINDOW_HEIGHT - y);
	}
}