#include "../declarations/ExampleApp.h"

void ExampleApp::Load() {
	level = new Scene(WINDOW_LENGTH, WINDOW_HEIGHT, window);
	player = new PlayerBase({ 100,100 }, "resources/textures/nike.png");
	thing = new Actor({ 300,300 }, "resources/textures/person.png");
	player->currentScene = level;

	level->AddActor(*thing);
	level->AddActor(*player);

	currentScene = level;
}


bool ExampleApp::Tick() {
	bool collide = player->CheckCollision(*thing);
	ImGui::Text("Player position:  x - %.2f  y - %.2f",player->GetPos().x, player->GetPos().y);
	ImGui::Text("IsColliding: %d", collide);
	/*system("cls");
	std::cout << collide;*/
	
	return true;
}