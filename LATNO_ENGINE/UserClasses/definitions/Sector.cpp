#include "../declarations/Sector.h"


void Sector::SetPlantHealth(float amount)
{


	if (!isDead)
	{
		if (plantHealth <= 0) SwapTexture("resources/textures/plants/10.png");
		else if (plantHealth < 10) SwapTexture("resources/textures/plants/1.png");
		else if (plantHealth < 20) SwapTexture("resources/textures/plants/2.png");
		else if (plantHealth < 30) SwapTexture("resources/textures/plants/3.png");
		else if (plantHealth < 40) SwapTexture("resources/textures/plants/4.png");
		else if (plantHealth < 50) SwapTexture("resources/textures/plants/5.png");
		else if (plantHealth < 60) SwapTexture("resources/textures/plants/6.png");
		else if (plantHealth < 70) SwapTexture("resources/textures/plants/7.png");
		else if (plantHealth < 80) SwapTexture("resources/textures/plants/8.png");
		else if (plantHealth < 90) SwapTexture("resources/textures/plants/9.png");
		else SwapTexture("resources/textures/plants/10.png");
	}

}

void Sector::Simulate(Json& jsonData)
{
	//adjust plant tier based on waterAmount and adjusts under and over watering
	if (waterAmount= 15)
	{
		plantHealth += 10;
		waterAmount + -10;
		minWater = 0;
	}
	else if (waterAmount <= -10)
	{
		plantHealth -= 10;
		maxWater = 0;
	}
	else
	{
		waterAmount -= 10;
		minWater = 0;
		maxWater = 0;
	}

	//cant be over or under watered for more than 2 days in a row
	if (waterAmount > 15)
	{
		maxWater++;
		if (maxWater > 2)
		{
			//kill plant
			isDead = true;
			SwapTexture("resources/textures/plants/10.png");
		}
	}
	else if (waterAmount < -10)
	{
		minWater--;
		if (minWater > 2)
		{
			//kill plant
			isDead = true;
			SwapTexture("resources/textures/plants/10.png");
		}
	}

	SetPlantHealth(plantHealth);

	float day = jsonData["globalInfo"]["timeID"];
	float percipitationAmount = jsonData["globalInfo"]["temperature"];
	float tempertureAmount = jsonData["globalInfo"]["precipitation"];

	float changeInPerc = (5 / 3) * percipitationAmount;
	float changeInTemp = 5 / (1 + exp(-0.37 * (tempertureAmount - 80)));

	waterAddAmount = jsonData["sectorInfo"][sectorID]["waterAddAmount"];
	waterAmount += waterAddAmount + changeInPerc + changeInTemp;



}
