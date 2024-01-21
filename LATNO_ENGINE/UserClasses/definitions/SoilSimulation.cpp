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

	field = new Sector * [24]();

	for (int i = 0; i < 24; i++)
		field[i] = new Sector[24];

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			float scale = .8f;
			int Pos_x = 548 - 57 + (x * (60 * scale) - (x * 1 * scale));
			int Pos_y = 128 - 70 + (y * (60 * scale) - (y * 1 * scale));
			currentScene->AddDynamicActor(Actor(Pos_x,Pos_y, {3,3}, "resources/textures/Field.png"));
		}
	}

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
}

bool SoilSimulation::Tick()
{
	if (InputManager::MouseDown(MOUSE_BUTTON_LEFT) && nextDay->CheckCollision(InputManager::GetMousePos()))
	{
		float* weather = new float[3];
		for (int i = 0; i < 3; i++) weather[i] = 0;

		Json data;


		JSONLoader::load("resources/JSON/sectors.json", data);

		JSONLoader::parseJSON(data, field, weather);

		for (int y = 0; y < 24; y++) {
			for (int x = 0; x < 24; x++) {
				field[y][x].Simulate(data);
			}
			data["globalInfo"]["temperature"] = 70 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / 20);
			data["globalInfo"]["precipitation"] = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / 3);

			//data["sectorInfo"][0]["plantHealth"] = 4;

			JSONLoader::Write(data);
		}



		return true;
	}
}

void SoilSimulation::FixedTick()
{
}

void SoilSimulation::End()
{
	delete SimulationScene;
}
