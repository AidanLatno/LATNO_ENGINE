#pragma once
#include "../../engine/declarations/Application.h"

class Sector : public Latno::Actor
{
private:
	float waterAddAmount;
public:
	// Json data
	float plantHealth;
	float waterAmount;

	void SetWaterAddAmount(float amount);
	float GetWaterAddAmount() { return waterAddAmount; }
	

};