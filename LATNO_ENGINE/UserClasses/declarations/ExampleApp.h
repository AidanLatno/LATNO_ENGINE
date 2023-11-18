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
	Actor* thing;

	void Load() override;
	bool Tick() override;

	int count = 0;
	float average = 0;
	float fps = 0;
};