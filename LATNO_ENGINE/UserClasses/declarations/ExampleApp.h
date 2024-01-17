#pragma once
#include "../../engine/declarations/Application.h"

using namespace Latno; // Not neccesary but makes it easier


/*
*/
class ExampleApp : public Application
{
public:
	Scene* level;
	SpawnActorButton* button;
	AudioManager* audio;
	PlayerExample* player;

	Pathfinder* pathFind;
	PhysicsController* physics;

	void Load() override;
	bool Tick() override;
	void End() override;
	void FixedTick() override;

	int count = 0;
	float average = 0;
	float fps = 0;
};