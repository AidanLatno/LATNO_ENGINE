#include "../declarations/ExampleApp.h"
#include "../../engine/declarations/JSONLoader.h"


static float TPS;
static int ticks = 0;
static float timer;

void ExampleApp::Load() {
	// Initialization of actors
	// Note: If done this way, you must delete all actors in the End() method to clean up memory.
	//		 You may also use smart pointers to manage memory automatically

	level = new Scene(WINDOW_LENGTH, WINDOW_HEIGHT, window);
	button = new SpawnActorButton( { WINDOW_LENGTH / 2,WINDOW_HEIGHT / 2 }, "resources/textures/nike.png" );

	player = new PlayerExample({ WINDOW_LENGTH / 2,WINDOW_HEIGHT / 2 }, "resources/textures/idle/pos1.png");
	pathFind = new Pathfinder;
	physics = new PhysicsController;

	pathFind->actorRef = player;

	physics->actorRef = button;

	player->currentScene = level;
	button->SetScene(level);

	level->AddActor(*button);
	level->AddActor(*player);
	

	currentScene = level;

	level->SetBackgroundColor(1, 1, 1);

	AppLog = new DevLog("AppLog");

	SoundDevice::Play(opening_music);

	AppLog->LOG("HELLO");
}


bool ExampleApp::Tick() {
	Coords mousePos = InputManager::GetMousePos();
	//if(InputManager::KeyDown(KEY_K))
	//{
	//	currentScene->AddDynamicActor(Actor({mousePos.x,mousePos.y},"resources/textures/person.png"));
	//	audio->PlayWavFile(rand() % 2 == 1 ? "resources/audio/pacman_intro.wav" : "resources/audio/pacman_dies.wav");
	//}



	physics->ApplyFloorGravity();

	if (InputManager::KeyDown(KEY_SPACE))
	{
		physics->ApplyForce(Coords(button->GetPos().x, button->GetPos().y - 100), 100);
	}

	if (InputManager::KeyDown(KEY_K))
	{
		//currentScene->AddDynamicActor(Actor({ mousePos.x,mousePos.y }, "resources/textures/person.png"));

		//std::vector<Coords> path = pathFind->GetPath(button->GetPos());

		/*std::cout << "Pressed\n";
		std::cout << "Size: " << path.size() << "\n";


		for (int i = 0; i < path.size(); ++i)
		{

		}*/

		//TextRenderer::Clear(currentScene);
		TextRenderer::AddText("HElLO world!", "test", currentScene, player->GetPos(), 200, 0.3);

		SoundDevice::Play(pacman_dead);

	


	}
	

	ImGui::Text("IsColliding: %d", player->CheckCollision(*button));

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

	timer += GLOBAL_DELTA_TIME;

	if (timer >= 1)
	{
		timer = 0;
		TPS = ticks;
		ticks = 0;
	}

	ImGui::Text("FixedTick TPS: %.4f", TPS);
	
	return true;
}

void ExampleApp::End()
{
	delete level;
	delete player;
	delete button;
	delete pathFind;
	delete physics;
}

void ExampleApp::FixedTick()
{
	ticks++;
}