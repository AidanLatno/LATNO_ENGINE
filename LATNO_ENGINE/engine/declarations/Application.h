#pragma once

#include "../../UserClasses/declarations/UserClasses.h"
namespace Latno
{
	/*
	* Class Name: Application
	* Purpose: This is the most important class as it is the application itself. It initalizes the app, runs all the logic for actors and the game, ect.
	* 
	* Variables:
	*	GLFWwindow* window
	*		- Window context created with glfw
	*		- Window where game is rendered
	*	DevLog* AppLog
	*		- Devlog instance used for logging app info
	*		- Do not log every frame as it causes significant performance drops
	*	Scene* currentScene
	*		- Points to the scene currently being rendered. Will cause an error if no scene is assigned.
	* 
	* Methods:
	*	void Run()
	*		- Main loop for application
	*	void BehaviorTick(double deltaTime)
	*		- Runs through the update methods for all behaviors
	*	void BehaviorLoad()
	*		- Runs through the start methods for all behaviors
	*	virtual void Load()
	*	virtual bool Tick(double deltaTime)
	*	void Startup()
	* 
	*/
	class Application
	{
	private:
		void Run();
		void BehaviorTick(double deltaTime);
		void BehaviorLoad();
	public:
		GLFWwindow* window;
		DevLog* AppLog;
		Scene* currentScene;
		
		virtual void Load();
		virtual bool Tick(double deltaTime);
		void Startup();

		~Application();
	};
}