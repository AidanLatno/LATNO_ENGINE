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
	float countDown = 10;
	float binCountDown = 0.2;
	int passed = 0;
	const std::string TrashSprites[3] = { "resources/textures/trash1.png","resources/textures/trash2.png", "resources/textures/can.png" };


	float RenderingMax = 0;
	float TickMax = 0;
	float SummonTrashMax = 0;
	float DynamicActorLogicMax = 0;
	float BoatTextureSwappingMax = 0;
	float CollisionWithBinMax = 0;
	float ScoreRenderingMax = 0;

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
	Latno_Entities::Actor* scorePtr;
	Latno_Entities::Actor* insPtr;


	ProgressBar* barPtr;

	


};