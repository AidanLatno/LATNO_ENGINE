#pragma once
#include "Component.h"

namespace Latno
{
	/*
	* Class Name: InputManager
	* Purpose: Querys all input events from keyboard presses to mouse clicks and position.
	* Note: This uses the enum system named "Key", which can be found in the Definitions.h
	*		file. The values of the enums are the same as the GLFW declarations, so they may
	*		be used interchangably.
	* 
	* Variables:
	*	oldState
	*		- Keeps track of the previous state of all keys, using the key value as the index
	*	window
	*		- Keeps a reference to the window context to pull input from
	* 
	* Methods:
	*	void SetWindow(GLFWwindow* _window)
	*		- Sets the window context to get input from
	*
	*	bool KeyPressed(Key key)
	*		- Will return true while a key is being pushed down
	*	bool KeyReleased(Key key)
	*		- Will return true if a key is not being pushed down
	*	bool KeyDown(Key key)
	*		- Will return true only once after a key is pressed until it is released
	*	bool KeyUp(Key key)
	*		- Will return true only once after a key is releassed until it is pressed again
	*
	*	Coords GetMousePos()
	*		- Returns the coordinates of the mouse
	*
	*	bool MousePressed(Key key)
	*		- Will return true while a mouse button is being pushed down
	*	bool MouseReleased(Key key)
	*		- Will return true if a mouse button is not being pushed down
	*
	*	bool MouseDown(Key key)
	*		- Will return true only once after a mouse button is pressed until it is released
	*	bool MouseUp(Key key)
	*		- Will return true only once after a mouse button is releassed until it is pressed again
	*/
	class InputManager
	{
	private:
		static int oldState[350];
		static GLFWwindow* window;
	public:
		static void SetWindow(GLFWwindow* _window);

		static bool KeyPressed(Key key);
		static bool KeyPressed(int ascii);
		static bool KeyReleased(Key key);
		static bool KeyReleased(int ascii);
		static bool KeyDown(Key key);
		static bool KeyDown(int ascii);
		static bool KeyUp(Key key);
		static bool KeyUp(int ascii);

		static Coords GetMousePos();

		static bool MousePressed(Key key);
		static bool MouseReleased(Key key);

		static bool MouseDown(Key key);
		static bool MouseUp(Key key);
	};
}