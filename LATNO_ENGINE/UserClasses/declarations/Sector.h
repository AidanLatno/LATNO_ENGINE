#pragma once
#include "../../engine/declarations/Application.h"

class Sector : public Latno::Actor
{
private:
	float waterAmount;
public:
	// Json data
	float plantHealth;
	float waterAddAmount;

	void SetWaterAmount(float amount);
	float GetWaterAddAmount() { return waterAmount; }
	

};