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

	countDown -= 1 * deltaTime;
	
	return true;
}

void Application::Startup(GLFWwindow* _window)
{
	window = _window;
	DevLog::CLEAR("EngineLog");
	DevLog::CLEAR("GL_ERROR_LOG");
	srand(time(NULL));

	Scene level(864, 980, window);

	Player player(475, 50, "resources/textures/cleaner.png");
	Latno_Entities::Actor land(475, 275, "resources/textures/land.png");
	Latno_Entities::Actor water(475, 275, "resources/textures/water.png");
	player.AddTag("player");
	


	water.SetScale({ 7, 5.5 });
	land.SetScale({ 10, 5.5 });
	player.SetScale({ 1, 0.7f });

	player.speed = 6;

	player.currentScene = &level;

	waterPtr = &water;
	backgroundPtr = &land;
	playerPtr = &player;
	levelPtr = &level;

	level.AddActor(water);
	level.AddActor(land);
	level.AddActor(player);

	Load();
}

void Application::Run()
{
	DevLog AppLog("AppLog");
	Timer DeltaCalc;
	double prevDeltaTime = 0;

	float timer;
	float difficultyMod = 0;

	while (true)
	{
		ImGui_ImplGlfwGL3_NewFrame();

		levelPtr->Render();

		DevLog::LOGLN("HELLO WORLD", "MainLog");

		if (!Tick(prevDeltaTime))
			return;

		if (countDown <= 0) {
			countDown = 2 - difficultyMod;

			Latno_Entities::Trash t(rand() % 764 + 100, 500, "resources/textures/trash1.png");
			t.AddTag("trash");
			levelPtr->AddDynamicActor(t);
		}

		for (int i = 0; i < levelPtr->dynamicActors.size(); i++)
		{
			levelPtr->dynamicActors[i].SetPos(levelPtr->dynamicActors[i].GetPos().x, levelPtr->dynamicActors[i].GetPos().y - 1);

			if (levelPtr->dynamicActors[i]->CheckCollision(playerPtr)) {
				 levelPtr->DestroyDynamicActor(i);
				 i--;
			}
		}
		
		prevDeltaTime = DeltaCalc.GetTime();
		DeltaCalc.Reset();

		ImGui::Text("DeltaTime: %f", prevDeltaTime);

		ImGui::Render();

		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
		glfwPollEvents(); // idk man
	}
}
