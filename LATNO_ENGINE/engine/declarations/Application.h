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
	double countDown = 10.0;
	float binCountDown = 0.2;
	int Lives = 3;
	const std::string TrashSprites[3] = { "resources/textures/trash1.png","resources/textures/trash2.png", "resources/textures/can.png" };

	// Declare variable pointers below

	Player *playerPtr;
	Scene *levelPtr;
	Latno_Entities::Actor* binPtr;
	Latno_Entities::Actor* backgroundPtr;
	Latno_Entities::Actor* waterPtr;
	Latno_Entities::Actor* num1Ptr;
	Latno_Entities::Actor* num2Ptr;
	Latno_Entities::Actor* num3Ptr;
	Latno_Entities::Actor* num4Ptr;
	Latno_Entities::Actor* heart1ptr;
	Latno_Entities::Actor* heart2ptr;
	Latno_Entities::Actor* heart3ptr;
	Latno_Entities::Actor* scorePtr;
	Latno_Entities::Actor* insPtr;
	Latno_Entities::Actor* rockPtr;

	ProgressBar* barPtr;

	//Declare Custom Methods below

	std::string GetNumPath(int num);
	


};