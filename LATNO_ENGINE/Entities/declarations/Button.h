#pragma once
#include "Actor.h"

namespace Latno
{
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
