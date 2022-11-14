#pragma once
#include "../../Shapes/declarations/Triangle.h"

using namespace Latno_Entities;

class Menu
{
	private:
		int TempWordlen = 0;

	public:
		int Length; // Up and down size
		int Width; // Left and right size
		Scene* MenuScene;
		std::string* Displays;
		AdvancedActor* Selector;
		int OptionsAmount;
		Menu(int Options,std::string DisplayNames[]);

		int OpenMenu(std::string Title,bool clear);
};