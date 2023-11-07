#pragma once
#include "../../engine/declarations/Application.h"

using namespace Latno;

class ExampleApp : public Latno::Application
{
public:
	Scene* level;
	PlayerBase* player;
	Actor* corners[4];

	void Load() override;
	bool Tick() override;
};