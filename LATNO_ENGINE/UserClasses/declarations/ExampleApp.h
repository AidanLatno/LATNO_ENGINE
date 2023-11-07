#pragma once
#include "../../engine/declarations/Application.h"

using namespace Latno; // Not neccesary but makes it easier


/*
*/
class ExampleApp : public Latno::Application
{
public:
	Scene* level;
	PlayerBase* player;

	void Load() override;
	bool Tick(double deltaTime) override;
};