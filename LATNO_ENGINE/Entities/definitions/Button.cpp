#include "../declarations/Button.h"
namespace Latno
{
	void Button::Update()
	{
		hovering = Hovering();
		

		if (!hovering)
		{
			NotHover();
			return;
		}
		

		OnHover();

		if (Pressed()) OnPress();
		if (Released()) OnRelease();
		
		
	}

	void Button::OnHover()
	{

	}

	void Button::OnPress()
	{

	}

	void Button::OnRelease()
	{

	}

	void Button::NotHover()
	{

	}

	bool Button::Hovering() { return CheckCollision(InputManager::GetMousePos()); }
	bool Button::Pressed() { return hovering && InputManager::MousePressed(MOUSE_BUTTON_LEFT); }
	bool Button::Released() { return hovering && InputManager::MouseUp(MOUSE_BUTTON_LEFT); }
}