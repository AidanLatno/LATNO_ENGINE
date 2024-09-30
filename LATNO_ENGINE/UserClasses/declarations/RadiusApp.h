#pragma once

#include "../../engine/declarations/Application.h"

class RadiusApp : public Latno::Application
{
public:
	Latno::Scene* scene;

	//Basic player w/ animation and movement
	Latno::AdvancedActor* player;

	//Coliding Actor
	Latno::Actor* box;


	void Load() override;
	bool Tick() override;
	void End() override;

};