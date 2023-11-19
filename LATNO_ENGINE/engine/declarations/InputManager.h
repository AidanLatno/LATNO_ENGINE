#pragma once
#include "Coords.h"

namespace Latno
{
	/*
	* Class Name: InputManager
	* Purpose: Querys all input events from keyboard presses to mouse clicks and position.
	* 
	* Variables:
	*	oldState
	*		- Keeps track of the previous state of all keys, using the key value as the index
	*	window
	*		- Keeps a reference to the window context to pull input from
	*/
	class InputManager
	{
	private:
		static int oldState[350];
		static GLFWwindow* window;
	public:
		static void SetWindow(GLFWwindow* _window);

		static bool KeyPressed(Key key);
		static bool KeyReleased(Key key);
		static bool KeyDown(Key key);
		static bool KeyUp(Key key);

		static Coords GetMousePos();

		static bool MousePressed(Key key);
		static bool MouseReleased(Key key);

		static bool MouseDown(Key key);
		static bool MouseUp(Key key);
	};
}