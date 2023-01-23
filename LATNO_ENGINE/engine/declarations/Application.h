#pragma once
#include "../../Animation/declarations/Animation.h"

// INCLUDE ALL OF YOUR CUSTOM MADE CLASSES HERE
//#include "../../UserClasses/declarations/example.h"

class Application
{
public:
	void BehaviorTick(double deltaTime);
	void BehaviorLoad();
	void Load();
	bool Tick();
	void Startup();

};