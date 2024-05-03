// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "UserClasses/declarations/ExampleApp.h"
#include "UserClasses//declarations/SoilSimulation.h"

int main()
{

	ExampleApp* app = new ExampleApp;
	app->Startup();
	delete app;

	return 0;
}