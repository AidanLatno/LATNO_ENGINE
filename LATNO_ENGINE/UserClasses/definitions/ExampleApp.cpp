#include "../declarations/ExampleApp.h"

void ExampleApp::Load() {
	// Initialization of actors
	// Note: If done this way, you must delete all actors in the End() method to clean up memory.
	//		 You may also use smart pointers to manage memory automatically

	level = new Scene(WINDOW_LENGTH, WINDOW_HEIGHT, window);
	player = new PlayerBase({ 100,100 }, "resources/textures/person.png");
	button = new SpawnActorButton( { WINDOW_LENGTH/2,WINDOW_HEIGHT/2 }, "resources/textures/nike.png" );
	audio = new AudioManager;
	player->currentScene = level;
	button->SetScene(level);


	level->AddActor(*player);
	level->AddActor(*button);

	currentScene = level;

	level->SetBackgroundColor(0, 0, 0);
}


bool ExampleApp::Tick() {
	Coords mousePos = InputManager::GetMousePos();
	if(InputManager::KeyDown(KEY_K))
	{
		currentScene->AddDynamicActor(Actor({mousePos.x,mousePos.y},"resources/textures/person.png"));
		audio->PlayWavFile(rand() % 2 == 1 ? "resources/audio/pacman_intro.wav" : "resources/audio/pacman_dies.wav");
	}
	if (InputManager::KeyPressed(KEY_K))
	{
		currentScene->dynamicActors[currentScene->dynamicActors.size() - 1].SetPos(mousePos);
		
	}

	ImGui::Text("IsColliding: %d", player->CheckCollision(mousePos));

	ImGui::Text("Mouse position:  x - %.2f  y - %.2f", mousePos.x, mousePos.y);
	
	ImGui::Text("Actor Count: %d", currentScene->dynamicActors.size());

	ImGui::Text("Sound instance count: %d", audio->sounds.size());
	for (Sound* s : audio->sounds)
	{
		ImGui::Text("   - Sound FilePath: %s", s->filename.c_str());
		ImGui::Text("      - IsPlaying: %d", s->isPlaying);
		ImGui::Text("      - IsRunning: %d", s->isRunning);
	}
	
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

void ExampleApp::End()
{
	delete level;
	delete player;
	delete button;
}