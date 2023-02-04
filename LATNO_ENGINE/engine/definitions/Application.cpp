#include "../declarations/Application.h"

void Application::BehaviorTick(double deltaTime)
{
	for (int i = 0; i < Latno::BehaviorList.size(); i++)
	{
		Latno::BehaviorList[i]->Update();
		LogPtr->LOGLN(std::to_string(Latno::BehaviorList[i]->id));
	}
}
void Application::BehaviorLoad()
{
	for (int i = 0; i < Latno::BehaviorList.size(); i++)
	{
		Latno::BehaviorList[i]->Start();
	}
}
void Application::Load()
{
	BehaviorLoad();
	srand(time(NULL));


	DevLog::LOGLN("App Load Finished", "MainLog");


}
bool Application::Tick()
{
	ScenePtr->Update();
	ScenePtr->Render();
	BehaviorTick(0);

	if (buttonPtr->CheckCollision(*playerPtr))
		playerPtr->SendBack();

	return true;
}

void Application::Startup()
{
	Player player(3, 3, 'p', "PLAYER");
	Button button(6, 4, 'e', "BUTTON");

	DevLog Log("Test");

	LogPtr = &Log;

	Scene Level(10, 10);

	ScenePtr = &Level;
	playerPtr = &player;
	buttonPtr = &button;
	ScenePtr->AddActor(player);
	ScenePtr->AddActor(button);
	
	Load();

	player.currentScene = &Level;

	while(Tick());
}

Application::Application()
{
	
}