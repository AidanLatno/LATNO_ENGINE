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
	*		- Override in your child classes.
			- Runs once on application load.
			- Use to initialize game state variables and actors
	*	virtual bool Tick(double deltaTime)
	*		- Override in your child classes.
	*		- Runs every frame
	*		- Use for game logic
	*	virtual void End()
	*		- Override in your child classes.
	*		- Gets called after the application's destructor is called.
	*		- Use to clean up memory.
	*	void Startup()
	*		- Call in LATNO_ENGINE.cpp after creating your instance of the application to start up the app.
	* 
	*/
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
		virtual void FixedTick();
		virtual void End();
		void Startup();

		~Application();
	};
}