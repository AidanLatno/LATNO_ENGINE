#pragma once

#include "../../UserClasses/declarations/UserClasses.h"
class Application
{
public:
	~Application();
	GLFWwindow* window;
	void BehaviorTick(double deltaTime);
	void BehaviorLoad();
	void Load();
	bool Tick(double deltaTime);
	void Startup(GLFWwindow* _window);
	void Run();

	// Declare variable pointers below
	Player *playerPtr;
	Scene *levelPtr;
	Button *buttonPtr;
	CollisionBox *wallPtr;
	CollisionBox* wall2Ptr;


};