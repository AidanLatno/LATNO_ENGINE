#pragma once

#include "../../engine/declarations/Engine.h"
// CUSTOM TEMPLATE CLASS
// NOT PART OF ENGINE

namespace Latno
{
	class Player : public PlayerBase
	{
		using PlayerBase::PlayerBase;
	public:
		int amountInBoat = 0;
		int carryingCapacity = 10;
		glm::vec2 sizerScale;

		void Start() override
		{
			sizerScale = scale;
			DevLog::LOGLN("Player Start Has been ran!", "MainLog");
		}
		void Update(double deltaTime) override
		{
			ManageInput(*currentScene, deltaTime);
		}

	};
}