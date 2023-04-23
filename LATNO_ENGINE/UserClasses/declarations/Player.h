#pragma once

#include "../../engine/declarations/Engine.h"
// CUSTOM TEMPLATE CLASS
// NOT PART OF ENGINE

class Player : public Latno_Entities::PlayerBase
{
	using PlayerBase::PlayerBase;
public:
	int amountInBoat = 0;
	int carryingCapacity = 10;
	int score;

	void Start() override
	{
		DevLog::LOGLN("Player Start Has been ran!", "MainLog");
	}
	void Update(double deltaTime) override
	{
		ManageInput(*currentScene, deltaTime);
	}

};