#pragma once
#include "../engine/declarations/Application.h"


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


	void Load() override;
	bool Tick() override;
	void FixedTick() override;
	void End() override;
};