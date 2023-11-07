#pragma once

#include "../../UserClasses/declarations/UserClasses.h"
namespace Latno
{
	class Application
	{
	private:
		void Run();
		void BehaviorTick();
		void BehaviorLoad();
	public:
		GLFWwindow* window;
		DevLog* AppLog;
		Scene* currentScene;
		
		virtual void Load();
		virtual bool Tick();
		void Startup();

		~Application();
	};
}