#include "../declarations/ExampleApp.h"

void ExampleApp::Load() {
	level = new Scene(WINDOW_LENGTH, WINDOW_HEIGHT, window);
	level2 = new Scene(WINDOW_LENGTH, WINDOW_HEIGHT, window);
	player = new PlayerBase({ 100,100 }, "resources/textures/nike.png");
	thing = new Actor({ 300,300 }, "resources/textures/person.png");
	player->currentScene = level;

	level->AddActor(*thing);
	level2->AddActor(*player);

	currentScene = level2;

	//player->speed = 200;
	//player->SetScale({ 2.7864, 1 });
}


bool ExampleApp::Tick() {
	ImGui::Text("Player position:  x - %.2f  y - %.2f",player->GetPos().x, player->GetPos().y);
	
	return true;
}