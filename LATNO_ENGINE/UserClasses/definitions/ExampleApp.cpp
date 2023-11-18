#include "../declarations/ExampleApp.h"

void ExampleApp::Load() {
	level = new Scene(WINDOW_LENGTH, WINDOW_HEIGHT, window);
	player = new PlayerBase({ 100,100 }, "resources/textures/nike.png");
	thing = new Actor({ 300,300 }, "resources/textures/person.png");
	player->currentScene = level;

	level->AddActor(*thing);
	level->AddActor(*player);

	currentScene = level;

	level->SetBackgroundColor(0, 0, 0);
}


bool ExampleApp::Tick() {
	

	bool collide = player->CheckCollision(*thing);
	ImGui::Text("Player position:  x - %.2f  y - %.2f",player->GetPos().x, player->GetPos().y);
	ImGui::Text("IsColliding: %d", collide);

	Coords mousePos = InputManager::GetMousePos();
	if(InputManager::KeyDown(KEY_K))
	{
		currentScene->AddDynamicActor(Actor({mousePos.x,mousePos.y},"resources/textures/person.png"));
	}
	ImGui::Text("Mouse position:  x - %.2f  y - %.2f", mousePos.x, mousePos.y);
	
	ImGui::Text("Actor Count: %d", currentScene->dynamicActors.size());
	
	average += GLOBAL_DELTA_TIME;
	count++;

	if (count >= 1000)
	{
		fps = 1/(average / count);
		count = 0;
		average = 0;
		std::cout << "RESET" << std::endl;
	}

	ImGui::Text("FPS: %.4f", fps);
	ImGui::Text("average: %.4f", average);
	ImGui::Text("count: %d", count);
	
	return true;
}