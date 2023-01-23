#include "../declarations/Application.h"

void Application::BehaviorTick(double deltaTime)
{
	for (int i = 0; i < Latno::BehaviorList.size(); i++)
	{
		Latno::BehaviorList[i]->Update();
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
	BehaviorTick(0);
	return true;
}

void Application::Startup()
{
	Load();
	//while(Tick());
}