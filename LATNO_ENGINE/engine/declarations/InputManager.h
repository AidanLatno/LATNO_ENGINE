#pragma once
#include "Coords.h"

namespace Latno
{
	class InputManager
	{
	public:
		static GLFWwindow* window;
		static bool KeyPressed(Key key);
		static bool KeyReleased(Key key);
		static Coords GetMousePos();
	};
}