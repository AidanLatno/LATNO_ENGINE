#include "../declarations/SoilSimulation.h"

void SoilSimulation::Load()
{
	SimulationScene = new Scene({ WINDOW_LENGTH,WINDOW_HEIGHT }, window);

	for (int i = 0; i < 24; ++i)
		feild[i] = new Sector[24];

	// HTTP REQUEST for field info


}

bool SoilSimulation::Tick()
{


	return true;
}

void SoilSimulation::FixedTick()
{
}

void SoilSimulation::End()
{
	delete SimulationScene;
}
