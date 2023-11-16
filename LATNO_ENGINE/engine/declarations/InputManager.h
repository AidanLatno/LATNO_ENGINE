#pragma once
#include "Definitions.h"


static class InputManager
{
private:
	static GLFWwindow* window;
public:
	static bool KeyPressed(Key key);
	static bool KeyReleased(Key key);
};