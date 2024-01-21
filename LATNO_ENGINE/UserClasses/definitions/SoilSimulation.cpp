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


	for (int y = 0; y < 24; y++)
	{
		for (int x = 0; x < 24; x++)
		{
			float scale = .4f;
			int Pos_x = 548 + (x * (115*scale) - (x * 15 * scale));
			int Pos_y = 128-57 + (y * (115*scale) - (y * 15 * scale));
			field[y][x] = Sector(Pos_x,Pos_y, { scale,scale }, "resources/textures/Field.png");
			currentScene->AddActor(field[y][x]);
			currentScene->AddDynamicActor(Actor(Coords(Pos_x, Pos_y), ""));
		}
	}

	
	// HTTP REQUEST for field info
	

}

bool SoilSimulation::Tick()
{
	if (InputManager::MouseDown(MOUSE_BUTTON_LEFT) && nextDay->CheckCollision(InputManager::GetMousePos()))
	{
		float* weather;
		Json data;

		JSONLoader::load("resources/JSON/sectors.json", data);

		JSONLoader::parseJSON(data, field, weather);
		
	}

	

	return true;
}

void SoilSimulation::FixedTick()
{
}

void SoilSimulation::End()
{
	delete SimulationScene;
}
