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
	float waterAmount;

	void SetPlantHealth(float amount);
	float GetPlantHealth() { return plantHealth; }
	
};