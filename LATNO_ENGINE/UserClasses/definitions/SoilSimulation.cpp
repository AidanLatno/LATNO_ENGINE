#include "../declarations/SoilSimulation.h"
#include "../../engine/declarations/JSONLoader.h"


void SoilSimulation::Load()
{
	// Definitions
	SimulationScene = new Scene({ WINDOW_LENGTH,WINDOW_HEIGHT }, window);
	nextDay = new NextDayButton({ 274, WINDOW_HEIGHT / 2 }, "resources/textures/Wood_Button.png");
	BG = new Actor({ WINDOW_LENGTH / 2, WINDOW_HEIGHT / 2 }, "resources/textures/Farm.png");
	BG->SetScale({ 14.4,13 });
	

	currentScene = SimulationScene;
	nextDay->SetScene(currentScene);
	currentScene->AddActor(*BG);
	currentScene->AddActor(*nextDay);
	

	TextRenderer::AddText("Next", "NextText", currentScene, { 220, WINDOW_HEIGHT / 2 + 40 }, 400, 0.5);

	// Initialize field as 2d dynamic array
	field = new Sector * [24]();

	for (int i = 0; i < 24; i++)
		field[i] = new Sector[24];

	// Get pos for field and add to scene
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			float scale = 2.8f;
			int Pos_x = 548 + 70 + (x * (115 * scale) - (x * 15 * scale));
			int Pos_y = 128 - 20 + (y * (115 * scale) - (y * 15 * scale));
			currentScene->AddDynamicActor(Actor(Pos_x,Pos_y, { scale,scale }, "resources/textures/Field.png"));
		}
	}
	// Get pos for plants and add to scene
	for (int y = 0; y < 24; y++)
	{
		for (int x = 0; x < 24; x++)
		{
			float scale = .8f;
			int Pos_x = 548-57 + (x * (60*scale) - (x * 1 * scale));
			int Pos_y = 128-70 + (y * (60*scale) - (y * 1 * scale));
			field[y][x] = Sector(Pos_x,Pos_y, { scale, scale }, "resources/textures/plants/5.png");
			currentScene->AddActor(field[y][x]);
			
		}
	}

	// Update sprites right away
	//Json data;
	//JSONLoader::load("resources/JSON/sectors.json", data);

	//for (int y = 0; y < 24; y++)
	//	for (int x = 0; x < 24; x++)
	//		field[y][x].SetPlantHealth(data["sectorInfo"][field[y][x].sectorID]["plantHealth"]);
}

bool SoilSimulation::Tick()
{

	if (disabled)
	{
		Json data;

		JSONLoader::load("resources/JSON/sectors.json", data);

		if (lastWeekCompleted < data["globalInfo"]["timeID"])
		{
			disabled = false;
			nextDay->SwapTexture("resources/textures/Wood_Button.png");
		}
		return true;
	}

	if (InputManager::MouseDown(MOUSE_BUTTON_LEFT) && nextDay->CheckCollision(InputManager::GetMousePos()))
	{


		float* weather = new float[3];
		for (int i = 0; i < 3; i++) weather[i] = 0;

		Json data;

		JSONLoader::load("resources/JSON/sectors.json", data);

		JSONLoader::parseJSON(data, field, weather);		

		disabled = true;
		nextDay->SwapTexture("resources/textures/Wood_Button_Off.png");
		lastWeekCompleted = data["globalInfo"]["timeID"];

		data["globalInfo"]["currentTemperature"] = 70 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / 20);
		data["globalInfo"]["currentPrecipitation"] = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / 3);

		for (int y = 0; y < 24; y++) {
			for (int x = 0; x < 24; x++) {
				Simulate(data, field[y][x]);
			}
		}
		JSONLoader::Write(data);
	}
	return true;
}

void SoilSimulation::FixedTick()
{
}

void SoilSimulation::End()
{
	delete SimulationScene;
	delete nextDay;
	delete BG;
}

void SoilSimulation::Simulate(Json& jsonData,Sector& sec)
{
	//adjust plant tier based on waterAmount and adjusts under and over watering
	if (sec.waterAmount >= 15)
	{
		sec.plantHealth += 10;
		sec.waterAmount + -10;
		sec.minWater = 0;
	}
	else if (sec.waterAmount <= -10)
	{
		sec.plantHealth -= 10;
		sec.maxWater = 0;
	}
	else
	{
		sec.waterAmount -= 10;
		sec.minWater = 0;
		sec.maxWater = 0;
	}

	//cant be over or under watered for more than 2 days in a row
	if (sec.waterAmount > 15)
	{
		sec.maxWater++;
		if (sec.maxWater > 2)
		{
			//kill plant
			sec.isDead = true;
			sec.SwapTexture("resources/textures/plants/10.png");
		}
	}
	else if (sec.waterAmount < -10)
	{
		sec.minWater--;
		if (sec.minWater > 2)
		{
			//kill plant
			sec.isDead = true;
			sec.SwapTexture("resources/textures/plants/10.png");
		}
	}

	sec.SetPlantHealth(sec.plantHealth);

	float percipitationAmount = jsonData["globalInfo"]["currentTemperature"];
	float tempertureAmount = jsonData["globalInfo"]["currentPrecipitation"];

	float changeInPerc = (5 / 3) * percipitationAmount;
	float changeInTemp = 5 / (1 + exp(-0.37 * (tempertureAmount - 80)));

	sec.waterAddAmount = jsonData["sectorInfo"][sec.sectorID]["waterAddAmount"];
	sec.waterAmount += sec.waterAddAmount + changeInPerc + changeInTemp;

	jsonData["sectorInfo"][sec.sectorID]["plantHealth"] = sec.GetPlantHealth();
	
}

