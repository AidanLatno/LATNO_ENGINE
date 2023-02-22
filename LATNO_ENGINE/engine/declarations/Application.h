#pragma once

#include "../../UserClasses/declarations/UserClasses.h"
class Application
{
public:
	void BehaviorTick(double deltaTime);
	void BehaviorLoad();
	void Load();
	bool Tick(double deltaTime);
	void Startup();
	void Run();

	// Declare variable pointers below
	Player *playerPtr;
	Scene *levelPtr;
	Button *buttonPtr;
	Enemy *enemyPtr;
	Rect *wallPtr;
	Rect* wall2Ptr;


};