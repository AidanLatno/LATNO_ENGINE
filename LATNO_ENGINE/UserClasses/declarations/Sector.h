#pragma once
#include "../../engine/declarations/Application.h"

class Sector : public Latno::Actor
{
	using Actor::Actor;
private:
public:
	// Json data
	float plantHealth;
	float waterAddAmount;
	float mineralHealth;
	float timeID;
	float temperture;
	float percipitation;
	float sectorID;
	float waterAmount;


	void SetWaterAmount(float amount);
	float GetWaterAddAmount() { return waterAmount; }
	
};