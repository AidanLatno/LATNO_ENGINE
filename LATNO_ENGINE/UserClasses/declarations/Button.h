#pragma once

#include "../../engine/declarations/Engine.h"
// CUSTOM TEMPLATE CLASS
// NOT PART OF ENGINE

class Button : public Actor
{
	using Actor::Actor;
public:
	Scene* currentScene;

	void Start() override
	{
		DevLog::LOGLN("Button Start Has been ran!", "MainLog");
	}
	void Update(double deltaTime) override
	{
		if (currentScene->ActorCollision(*this))
		{
			position.x = rand() % currentScene->sizeX;
			position.y = rand() % currentScene->sizeY;
		}
	}

};