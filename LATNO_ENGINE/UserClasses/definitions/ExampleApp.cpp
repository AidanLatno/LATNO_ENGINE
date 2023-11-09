#include "../declarations/ExampleApp.h"

void ExampleApp::Load() {
	level = new Scene(WINDOW_HEIGHT, WINDOW_LENGTH, window);
	player = new PlayerBase({ 100,100 }, "resources/textures/nike.png");
	player->currentScene = level;

	level->AddActor(*player);

	currentScene = level;
	player->speed = 200;
}


bool ExampleApp::Tick() {
	return true;
}