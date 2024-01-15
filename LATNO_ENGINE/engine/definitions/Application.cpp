#include "../declarations/Application.h"
static float fixedTime = 0;
static float count = 0;

namespace Latno
{
	Application::~Application()
	{
		ImGui_ImplGlfwGL3_Shutdown();
		ImGui::DestroyContext();

		glfwTerminate();
	}

	void Application::BehaviorTick()
	{
		for (int i = 0; i < Latno::BehaviorList.size(); i++)
		{
			Latno::BehaviorList[i]->Update();
		}
	}
	void Application::Load()
	{
		// To be overriden
	}
	void Application::BehaviorLoad()
	{
		for (int i = 0; i < Latno::BehaviorList.size(); i++)
		{
			Latno::BehaviorList[i]->Start();
		}
		AppLog = new DevLog("AppLog");

		DevLog::LOGLN("App Load Finished", "EngineLog");
	}
	bool Application::Tick()
	{
		// To be overriden
		return true;
	}

	void Application::End()
	{
		// To be overriden
		// Use for memory cleanup
	}

	void Application::FixedTick()
	{
		// To be overriden
		// Runs 20 times every second
	}

	void Application::Startup()
	{
		if (!glfwInit())
		{
			return;
		}

		// vv Make GL Version core instead of compact vv
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		// ^^ Make GL Version core instead of compat ^^


		window = glfwCreateWindow(WINDOW_LENGTH, WINDOW_HEIGHT, "LATNO ENGINE", NULL, NULL); // Creates window context
		if (!window)
		{
			glfwTerminate();
			return;
		}
		//glfwSetWindowSizeLimits(window, WINDOW_LENGTH, WINDOW_HEIGHT, WINDOW_LENGTH, WINDOW_HEIGHT);
		glfwMakeContextCurrent(window);

		glfwSwapInterval(1); // Syncs swap interval with vsync

		if (glewInit() != GLEW_OK) // Checks glew state for errors
			std::cout << "ERROR!" << std::endl;

		// Enabling Blending
		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		// ^^^ INITIALIZATION ^^^
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();

		InputManager::SetWindow(window);

		DevLog::CLEAR("EngineLog");
		DevLog::CLEAR("GL_ERROR_LOG");
		srand(time(NULL));
		
		Load();
		BehaviorLoad();
		Run();

		delete this;
	}

	void Application::Run()
	{
		auto prevTime = std::chrono::high_resolution_clock::now();

		while (true)
		{
			// vv RENDERING vv
			ImGui_ImplGlfwGL3_NewFrame();
			currentScene->Render();


			// vv TICK vv
			if (!Tick())
				return;
			if (fixedTime > 0.05f)
			{
				fixedTime -= 0.05f;
				FixedTick();
			}

			BehaviorTick();

			count += GLOBAL_DELTA_TIME;
			ImGui::Text("Seconds: %.2f", count);
			

			ImGui::Render();
			

			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
			glfwSwapBuffers(window);
			glfwPollEvents();

			auto currentTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> elapsedTime = currentTime - prevTime;
			GLOBAL_DELTA_TIME = elapsedTime.count();
			fixedTime += GLOBAL_DELTA_TIME;

			prevTime = currentTime;
		}
	}
}