#include "../declarations/Application.h"

void Application::BehaviorTick(double deltaTime)
{
	for (int i = 0; i < Latno::BehaviorList.size(); i++)
	{
		Latno::BehaviorList[i]->Update(deltaTime);
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
	DevLog::LOGLN("App Load Finished", "MainLog");
	Run();

}
bool Application::Tick(double deltaTime)
{
	BehaviorTick(deltaTime);
	return true;
}

void Application::Startup()
{
	srand(time(NULL));
	Scene level(10, 10);
	Button button(1, 1, ToChar("purple"), "BUTTON");
	Player player(3,3,ToChar("blue"), "Player");
	Enemy enemy(7, 7, ToChar("red"), "Enemy");

	
	level.AddActor(player);
	level.AddActor(button);
	level.AddActor(enemy);

	enemyPtr = &enemy;
	buttonPtr = &button;
	levelPtr = &level;
	playerPtr = &player;

	button.currentScene = levelPtr;
	player.currentScene = levelPtr;
	Load();
}

void Application::Run()
{
	DevLog AppLog("AppLog");
	Timer DeltaCalc;
	double prevDeltaTime = 0;

	while (true)
	{
		levelPtr->Update();
		levelPtr->Render();
		enemyPtr->Chase(*levelPtr, *playerPtr);

		if (!Tick(prevDeltaTime))
			return;

		AppLog.LOGLN(std::to_string(prevDeltaTime));
		prevDeltaTime = DeltaCalc.GetTime();
		DeltaCalc.Reset();
	}
}
