// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "UserClasses/declarations/ExampleApp.h"
#include "UserClasses//declarations/SoilSimulation.h"

int main()
{
	// Replace "your_audio_file.wav" with the actual path to your audio file

	SoilSimulation* app = new SoilSimulation;
	app->Startup();
	delete app;


	//AudioManager::play("resources/audio/pacman_intro.wav");
	//AudioManager man("resources/audio/canary.wav");
	//man.play();

	//// Your main application loop
	//int counter = 0;
	//while (true) {
	//	std::cout << counter << std::endl;
	//	counter++;
	//}

	return 0;

}