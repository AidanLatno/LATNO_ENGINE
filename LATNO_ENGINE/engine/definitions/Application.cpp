#include "../declarations/Application.h"

Application::~Application() 
{
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
}

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
	DevLog::LOGLN("App Load Finished", "EngineLog");
	Run();

}
bool Application::Tick(double deltaTime)
{
	BehaviorTick(deltaTime);
	
	return true;
}

void Application::Startup(GLFWwindow* _window)
{
	window = _window;
	DevLog::CLEAR("EngineLog");
	DevLog::CLEAR("GL_ERROR_LOG");
	srand(time(NULL));

	Scene level(864, 988, window);

	Player player(100, 100, "resources/textures/cleaner.png");
	Latno_Entities::Actor land(864 / 2, 988 / 2, "resources/textures/land.png");
	Latno_Entities::Actor water(864 / 2, 988 / 2, "resources/textures/water.png");

	water.SetScale({ 50, 50 });
	land.SetScale({ 50, 50 });
	player.SetScale({ 10, 10 });

	player.currentScene = &level;

	waterPtr = &water;
	backgroundPtr = &land;
	playerPtr = &player;
	levelPtr = &level;

	level.AddActor(player);
	level.AddActor(water);
	level.AddActor(land);

	Load();
}

void Application::Run()
{
	DevLog AppLog("AppLog");
	Timer DeltaCalc;
	double prevDeltaTime = 0;

	while (true)
	{
		ImGui_ImplGlfwGL3_NewFrame();

		levelPtr->Render();

		DevLog::LOGLN("HELLO WORLD", "MainLog");

		if (!Tick(prevDeltaTime))
			return;
			

		prevDeltaTime = DeltaCalc.GetTime();
		DeltaCalc.Reset();

		ImGui::Render();

		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
		glfwPollEvents(); // idk man
	}
}
