#pragma once
#include "Engine.h"

#include "../../UserClasses/declarations/UserClasses.h"


class Application
{
private:
	void BehaviorTick(double deltaTime);
	void BehaviorLoad();
	void Load();
	bool Tick();

public:
	void Startup();
	Application();
	Scene *ScenePtr;
	Player *playerPtr;
	Actor *buttonPtr;
	DevLog *LogPtr;
};