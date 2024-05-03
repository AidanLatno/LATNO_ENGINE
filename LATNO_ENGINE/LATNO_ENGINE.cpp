// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "UserClasses/declarations/ExampleApp.h"
#include "UserClasses/declarations/SillyApp.h"

int main()
{

	SillyApp* app = new SillyApp;
	app->Startup();
	delete app;

	return 0;
}