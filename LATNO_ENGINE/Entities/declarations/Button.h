#pragma once
#include "Actor.h"

namespace Latno
{
	/*
	* Class Name: Button
	* Purpose: This class is meant to be inherited and overloaded, however you can use it with
	*		   just the Hovering(), Pressed() and Released() methods. This class is meant to be
	*		   a clickable actor with customizable behaviors for all kinds of events such as
	*		   being clicked, hoving over it, and releasing the button.
	* Parents: Actor -> Component -> Behavior
	* 
	* Update Override: Checks for events and calls the corresponding virtual methods
	* 
	* Virtual Methods:
	*	void OnHover
	*		- Called when the mouse hovers over the button
	*	void OnPress
	*		- Called repeatedly whilst left click is being held over the button
	*	void OnRelease
	*		- Called once after left click is released
	*	void NotHover
	*		- Called if the mouse is not hovering over the button
	* 
	* Methods:
	*	bool Hovering
	*		- returns true if the mouse is hovering over the button
	*	bool Pressed()
	*		- returns true if the left mouse button is being pressed whilst over the button
	*	bool Released()
	*		- returns true once after the button is released
	*	
	*/
	class Button : public Actor
	{
		using Actor::Actor;
	private:
		void Update() override;
		bool hovering = false;
	public:
		virtual void OnHover();
		virtual void OnPress();
		virtual void OnRelease();
		virtual void NotHover();

		bool Hovering();
		bool Pressed();
		bool Released();
	};
}
