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
