#pragma once

#include "../../UserClasses/declarations/UserClasses.h"
namespace Latno
{
	class Application
	{
	public:
		~Application();
		GLFWwindow* window;
		DevLog* AppLog;
		void BehaviorTick(double deltaTime);
		void BehaviorLoad();
		void Load();
		bool Tick(double deltaTime);
		void Startup(GLFWwindow* _window);
		void Run();
		Scene* currentScene;

		// Declare variable pointers below
		

		Actor* man;
		Scene* level;

		//Declare Custom Methods below


	};
}