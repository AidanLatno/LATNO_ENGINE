#include "../declarations/InputManager.h"
namespace Latno
{
	GLFWwindow* InputManager::window = NULL;
	int InputManager::oldState[350] = { 0 };

	void InputManager::SetWindow(GLFWwindow* _window)
	{
		window = _window;
	}

	bool InputManager::KeyPressed(Key key)
	{
		return glfwGetKey(window, key) == GLFW_PRESS;
	}

	bool InputManager::KeyPressed(int ascii)
	{
		return glfwGetKey(window, ascii) == GLFW_PRESS;
	}

	bool InputManager::KeyReleased(Key key)
	{
		return glfwGetKey(window, key) == GLFW_RELEASE;
	}

	bool InputManager::KeyReleased(int ascii)
	{
		return glfwGetKey(window, ascii) == GLFW_RELEASE;
	}

	bool InputManager::KeyDown(Key key)
	{
		int newState = glfwGetKey(window, key);
		if (newState == GLFW_PRESS && oldState[key] == GLFW_RELEASE) {
			oldState[key] = newState;
			return true;
		}
		oldState[key] = newState;
		return false;
	}

	bool InputManager::KeyDown(int ascii)
	{
		int newState = glfwGetKey(window, ascii);
		if (newState == GLFW_PRESS && oldState[ascii] == GLFW_RELEASE) {
			oldState[ascii] = newState;
			return true;
		}
		oldState[ascii] = newState;
		return false;
	}

	bool InputManager::KeyUp(Key key)
	{
		int newState = glfwGetKey(window, key);
		if (newState == GLFW_RELEASE && oldState[key] == GLFW_PRESS) {
			oldState[key] = newState;
			return true;
		}
		oldState[key] = newState;
		return false;
	}
	bool InputManager::KeyUp(int ascii)
	{
		int newState = glfwGetKey(window, ascii);
		if (newState == GLFW_RELEASE && oldState[ascii] == GLFW_PRESS) {
			oldState[ascii] = newState;
			return true;
		}
		oldState[ascii] = newState;
		return false;
	}

	Coords InputManager::GetMousePos()
	{
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return Coords(x, WINDOW_HEIGHT - y);
	}

	bool InputManager::MousePressed(Key key)
	{
		return glfwGetMouseButton(window, key) == GLFW_PRESS;
	}

	bool InputManager::MouseReleased(Key key)
	{
		return glfwGetMouseButton(window, key) == GLFW_RELEASE;
	}

	bool InputManager::MouseDown(Key key)
	{
		int newState = glfwGetMouseButton(window, key);
		if (newState == GLFW_PRESS && oldState[key] == GLFW_RELEASE) {
			oldState[key] = newState;
			return true;
		}
		oldState[key] = newState;
		return false;
	}

	bool InputManager::MouseUp(Key key)
	{
		int newState = glfwGetMouseButton(window, key);
		if (newState == GLFW_RELEASE && oldState[key] == GLFW_PRESS) {
			oldState[key] = newState;
			return true;
		}
		oldState[key] = newState;
		return false;
	}
}
