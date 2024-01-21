#pragma once
#include "../../engine/declarations/Application.h"
#include "../../engine/declarations/JSONLoader.h"

class Sector : public Latno::Actor
{
	using Actor::Actor;
private:
	
public:
	float plantHealth;
	float waterAddAmount;
	float mineralHealth;
	float sectorID;
	float waterAmount;
	int maxWater = 0;
	int minWater = 0;

	bool isDead = false;

	void SetPlantHealth(Json& jsonData, Sector field);
	float GetPlantHealth() { return plantHealth; }
	
};