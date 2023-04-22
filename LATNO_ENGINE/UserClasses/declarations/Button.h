#pragma once

#include "../../engine/declarations/Engine.h"
// CUSTOM TEMPLATE CLASS
// NOT PART OF ENGINE

class Button : public AdvancedActor
{
	using AdvancedActor::AdvancedActor;
public:
	void Start() override
	{
		DevLog::LOGLN("Button Start Has been ran!", "MainLog");
	}
	void Update(double deltaTime) override
	{
		if (currentScene->ActorCollision(*this))
		{
			SetPos({ rand() % currentScene->sizeY, GetPos().y });
			SetPos({ GetPos().x, rand() % currentScene->sizeY });
		}
	}

};