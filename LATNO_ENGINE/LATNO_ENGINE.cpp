// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "UserClasses/declarations/ExampleApp.h"

int main()
{
	// Replace "your_audio_file.wav" with the actual path to your audio file

	/*ExampleApp* app = new ExampleApp;

	app->Startup();

	delete app;*/


	//AudioManager::play("resources/audio/pacman_intro.wav");

	AudioManager man("resources/audio/pacman_intro.wav");
	man.play();

	// Your main application loop
	int counter = 0;
	while (true) {
		if (counter % 200 == 0) system("cls");
		std::cout << counter << std::endl;
		counter++;
	}

	return 0;

}