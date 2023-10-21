#include "../declarations/Application.h"
namespace Latno
{
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
		AppLog = new DevLog("AppLog");

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
		
		Scene levelInit(WINDOW_LENGTH, WINDOW_HEIGHT, window);
		PlayerBase playerInit({ 200,200 }, "resources/textures/person.png");
		
		levelInit.AddActor(playerInit);

		level = &levelInit;
		player = &playerInit;
		currentScene = level;

		player->speed = 200;
		Load();


	}

	void Application::Run()
	{
		Timer DeltaCalc;
		float prevDeltaTime = 0;

		float timer;
		float difficultyMod = 0;

		while (true)
		{
			// vv RENDERING vv
			ImGui_ImplGlfwGL3_NewFrame();
			currentScene->Render();


			// vv TICK vv
			if (!Tick(prevDeltaTime))
				return;
			
			player->ManageInput(*level, prevDeltaTime);
			

			prevDeltaTime = DeltaCalc.GetTime();
			DeltaCalc.Reset();

			ImGui::Render();

			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
			glfwSwapBuffers(window);
			glfwPollEvents();

		}
	}
}