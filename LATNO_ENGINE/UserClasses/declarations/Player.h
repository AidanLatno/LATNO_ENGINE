#pragma once

#include "../../engine/declarations/Engine.h"
// CUSTOM TEMPLATE CLASS
// NOT PART OF ENGINE

class Player : public PlayerBase
{
	using PlayerBase::PlayerBase;
public:
	Scene* currentScene;

	void Start() override
	{
		DevLog::LOGLN("Player Start Has been ran!", "MainLog");
	}
	void Update(double deltaTime) override
	{
		Move(*currentScene);
	}

};