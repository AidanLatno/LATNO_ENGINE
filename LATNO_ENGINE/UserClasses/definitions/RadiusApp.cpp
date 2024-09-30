#include "../UserClasses/declarations/RadiusApp.h"

void RadiusApp::Load()
{
	player = new Latno::AdvancedActor(WINDOW_LENGTH / 2, WINDOW_HEIGHT / 2, "resources/textures/BlackCircle.png", "RADIUS");
	box = new Latno::Actor(WINDOW_LENGTH / 2, WINDOW_HEIGHT / 2, "resources/textures/BlackCircle.png", "RADIUS");
	scene = new Latno::Scene({ WINDOW_LENGTH,WINDOW_HEIGHT }, window);

	currentScene = scene;
	player->currentScene = scene;
	

	currentScene->AddActor(*box);
	currentScene->AddActor(*player);

	scene->SetBackgroundColor(1, 1, 1);

}


bool RadiusApp::Tick()
{
	ImGui::Text("IsColliding: %d", player->CheckCollision(*box));
	player->speed = 100.0f;

	if (Latno::InputManager::KeyPressed(KEY_A))
	{
		player->direction = Latno::LEFT;
		player->MoveForward();
	}
	if (Latno::InputManager::KeyPressed(KEY_S))
	{
		player->direction = Latno::DOWN;
		player->MoveForward();
	}
	if (Latno::InputManager::KeyPressed(KEY_D))
	{
		player->direction = Latno::RIGHT;
		player->MoveForward();
	}
	if (Latno::InputManager::KeyPressed(KEY_W))
	{
		player->direction = Latno::UP;
		player->MoveForward();
	}

	return true;
}

void RadiusApp::End()
{
	delete scene;
	delete player;
}