#pragma once
#include "../../engine/declarations/Application.h"


class Sector : public Latno::Actor
{
	using Actor::Actor;
private:
	
public:
	float plantHealth;
	float waterAddAmount;
	float mineralHealth;
	float sectorID;
	float waterAmount = 10;
	int maxWater = 0;
	int minWater = 0;

	bool isDead = false;

	void SetPlantHealth(float amount);
	float GetPlantHealth() { return plantHealth; }
	
};