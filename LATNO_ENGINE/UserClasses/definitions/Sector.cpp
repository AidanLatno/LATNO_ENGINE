#include "../declarations/Sector.h"
#include 

void Sector::SetPlantHealth(float amount)
{
	plantHealth = amount;
	/*
	Default Water Level: 1000
	
	10 sprites -> 10 health for each sprite

	Current watter has to be relative to plant health in the begining

	the plants grow 1 level when water on node is greater than 15
	Absorbs 10
	if the water on node is greater than ___ for __ time, then it dies

	the plants loose 1 level when water on node is less than -15
	if the water goes too low it imediate dies

	percipitation increases the water on each node by (percipitationAmount/100)*total water

	HealthCost = [waterAvailable/10] + 
	                
	waterAvailable += [percipForm + waterAvailable] + [waterAvailable - tempertureFormula]

	percipForm = (5/3)x


	tempertureFormula = 5/(1+e^(-0.37(x-80))
	
	
	*/
	if (plantHealth <= 0) SwapTexture("resources/textures/plants/10.png");
	else if(plantHealth < 10) SwapTexture("resources/textures/plants/1.png");
	else if (plantHealth < 20) SwapTexture("resources/textures/plants/2.png");
	else if (plantHealth < 30) SwapTexture("resources/textures/plants/3.png");
	else if (plantHealth < 40) SwapTexture("resources/textures/plants/4.png");
	else if (plantHealth < 50) SwapTexture("resources/textures/plants/5.png");
	else if (plantHealth < 60) SwapTexture("resources/textures/plants/6.png");
	else if (plantHealth < 70) SwapTexture("resources/textures/plants/7.png");
	else if (plantHealth < 80) SwapTexture("resources/textures/plants/8.png");
	else if (plantHealth < 90) SwapTexture("resources/textures/plants/9.png");
	else if (plantHealth < 100) SwapTexture("resources/textures/plants/10.png");

	


	
}
	


