#pragma once
#include "../../engine/declarations/Application.h"

class Sector : public Latno::Actor
{
	using Actor::Actor;
private:
	float plantHealth;
public:
	// Json data
	
	float waterAddAmount;
	float mineralHealth;
	float sectorID;
	float waterAmount;


	void SetPlantHealth(float amount);
	float GetPlantHealth() { return plantHealth; }
	
};