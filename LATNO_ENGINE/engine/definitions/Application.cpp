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

	Scene level(20, 20);
	Button button(1, 1, ToChar("purple"), "BUTTON");
	Player player(16, 16,ToChar("blue"), "Player");
	Rect Wall(6, 9, 15, 12, ToChar("yellow"), "WALL");
	Rect Wall2(13, 5, 15, 12, ToChar("yellow"), "WALL2");

	Enemy enemy(3, 3, ToChar("red"), "Enemy");

	enemy.currentScene = &level;

	
	level.AddActor(player);
	level.AddActor(button);
	level.AddActor(enemy);
	level.AddRect(Wall);
	level.AddRect(Wall2);

	wall2Ptr = &Wall2;
	wallPtr = &Wall;
	enemyPtr = &enemy;
	buttonPtr = &button;
	levelPtr = &level;
	playerPtr = &player;

	button.currentScene = levelPtr;
	player.currentScene = levelPtr;
	Load();
}

/*
f = .2
1 = .2
20

*/

void Application::Run()
{
	DevLog AppLog("AppLog");
	Timer DeltaCalc;
	double prevDeltaTime = 0;

	while (true)
	{
		levelPtr->Update();
		levelPtr->Render();

		std::cout << 1/prevDeltaTime << '\n';

		enemyPtr->Chase(*levelPtr, *playerPtr);

		if (!Tick(prevDeltaTime))
			return;

		prevDeltaTime = DeltaCalc.GetTime();
		DeltaCalc.Reset();
	}
}
