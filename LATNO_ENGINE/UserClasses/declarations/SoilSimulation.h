#pragma once
#include "../engine/declarations/Application.h"


using namespace Latno;

class SoilSimulation : public Application
{
private:

public:
	void Load() override;
	bool Tick() override;
	void FixedTick() override;
	void End() override;
};