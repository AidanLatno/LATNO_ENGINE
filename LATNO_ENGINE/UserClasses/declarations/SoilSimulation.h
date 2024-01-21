#pragma once
#include "../engine/declarations/Application.h"
#include "../engine/declarations/JSONLoader.h"


using namespace Latno;

class SoilSimulation : public Application
{
private:

public:
	// Scene Pointers
	Scene* SimulationScene;

	// Actor Pointers
	NextDayButton* nextDay;
	Actor* BG;
	Sector** field;


	// Tool pointers

	// Variables
	int lastWeekCompleted = 0;
	bool disabled = false;


	void Load() override;
	bool Tick() override;
	void FixedTick() override;
	void End() override;

	void Simulate(Json& jsonData, Sector& sec);
};