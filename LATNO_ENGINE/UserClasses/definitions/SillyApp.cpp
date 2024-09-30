#include "../declarations/SillyApp.h"

void SillyApp::Load()
{
	player = new TopDownPlayer({ WINDOW_LENGTH / 2, WINDOW_HEIGHT / 2 }, { 2,2 }, "resources/textures/Idle/pos1.png");
	background = new Latno::Actor({ WINDOW_LENGTH / 2, WINDOW_HEIGHT / 2 }, { 30,30 }, "resources/textures/water.png");
	game = new Latno::Scene({ WINDOW_LENGTH,WINDOW_HEIGHT },window);

	background->AddTag("move_c_1");
	background->speed = 100;

	player->SetMoverTag("move_c_1");

	currentScene = game;
	player->currentScene = currentScene;

	currentScene->AddActor(*background);
	currentScene->AddActor(*player);


}

bool SillyApp::Tick()
{
	return true;
}

void SillyApp::End()
{
	delete game;
	delete player;
}