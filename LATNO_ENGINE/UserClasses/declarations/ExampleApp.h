#pragma once
#include "../../engine/declarations/Application.h"

using namespace Latno; // Not neccesary but makes it easier


/*
*/
class ExampleApp : public Application
{
public:
	Scene* level;
	Scene* level2;
	PlayerBase* player;
	Actor* thing;

	void Load() override;
	bool Tick() override;
};