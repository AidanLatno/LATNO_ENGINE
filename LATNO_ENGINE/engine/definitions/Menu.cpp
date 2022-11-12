#include "../declerations/Menu.h"

Menu::Menu(int Options,std::string DisplayNames[])
{
	Displays = new std::string[Options];
	for(int i = 0; i < Options; i++)
	{
		Displays[i] = DisplayNames[i];
		if(TempWordlen < DisplayNames[i].length())
			TempWordlen = DisplayNames[i].length();
	}
	Width = TempWordlen + 4;
	Length = Options * 2 - 1;
	MenuScene = new Scene(Width,Length);
	Selector = new AdvancedActor(0,0,'>',"SELECTOR");
	MenuScene->AddActor(*Selector);
	OptionsAmount = Options;
}

int Menu::OpenMenu(std::string Title = "",bool clear = true)
{
	bool Rep = true;
	int TempY = 0;
	std::string TempStr;
	while(Rep)
	{
		MenuScene->Update();

		TempWordlen = Displays[0].length();
		TempY = 0;
		for(int i = 0; i < OptionsAmount; i++)
		{
			TempY = i;
			TempY *= 2;
			TempStr = Displays[i];
			for(int _i = 0; _i < Displays[i].length(); _i++)
				MenuScene->grid[TempY][_i + 2] = TempStr[_i];
		}
		if(clear)
			system("clear");
		std::cout << Title << '\n';
		MenuScene->Render(true,false);
		char Input;
		Input = getch();
		if(Input == 'w' || Input == 'W')
		{
			Selector->direction = UP;
			if(Selector->position.y != 0)
			{
				Selector->MoveFoward(*MenuScene);
				Selector->MoveFoward(*MenuScene);
			}
		}
		else if(Input == 's' || Input == 'S')
		{
			Selector->direction = DOWN;
			if(Selector->position.y != MenuScene->GetSize().y - 1)
			{
				Selector->MoveFoward(*MenuScene);
				Selector->MoveFoward(*MenuScene);
			}
		}
		else if(Input == '\n')
		{
			for(int i = 0; i < OptionsAmount; i++)
			{
				if(Selector->position.y == i * 2)
					return i;
			}
		}
	}
	return -1;
}