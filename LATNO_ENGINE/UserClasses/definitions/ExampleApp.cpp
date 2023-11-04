#include "../declarations/ExampleApp.h"

void ExampleApp::Load() {
	level = new Scene(WINDOW_HEIGHT, WINDOW_LENGTH, window);
	player = new PlayerBase({ 100,100 }, "resources/textures/person.png");

	level->AddActor(*player);

	currentScene = level;
	player->speed = 200;
}


bool ExampleApp::Tick(double deltaTime) {
	player->ManageInput(*level);
	return true;
}