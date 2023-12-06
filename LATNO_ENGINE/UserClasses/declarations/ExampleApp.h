#pragma once
#include "../../engine/declarations/Application.h"

using namespace Latno; // Not neccesary but makes it easier


/*
*/
class ExampleApp : public Application
{
public:
	Scene* level;
	PlayerBase* player;
	SpawnActorButton* button;
	AudioManager* audio;

	void Load() override;
	bool Tick() override;
	void End() override;

	int count = 0;
	float average = 0;
	float fps = 0;
};