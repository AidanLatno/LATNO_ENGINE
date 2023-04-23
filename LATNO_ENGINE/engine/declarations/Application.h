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
	float countDown = 10;
	Player *playerPtr;
	Scene *levelPtr;
	Button *buttonPtr;
	CollisionBox *wallPtr;
	CollisionBox* wall2Ptr;
	Latno_Entities::Actor* backgroundPtr;
	Latno_Entities::Actor* waterPtr;
	ProgressBar* barPtr;

	const std::string TrashSprites[2] = { "resources/textures/trash1.png","resources/textures/trash2.png" };

	int carryingCapacity;

};