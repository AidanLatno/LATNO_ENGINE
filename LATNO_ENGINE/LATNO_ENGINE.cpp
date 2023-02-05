// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "engine/declarations/Application.h"
#include "exceptions/declarations/RuntimeException.h"

int main() {

	Application* app = new Application();

	app->Startup();

	delete app;

    /*
     bool running = true;
     while(running) 
     {
         try 
         {
             //tick
             running = false;
         }
         catch (runtimeexception e) 
         {
             running = false;
             //print error 
         }
     }
    */

	/*
	srand(time(NULL));
	bool GameRunning = true;
	std::string MenuElements[3] = { "Continue","Settings","Quit" };
	 Menu MainMenu(3,MenuElements);

	Actor Button(12, 12, ToChar("purple"), "BUTTON");
	Rect Turny1(10, 8, 12, 8, ToChar("yellow"), "TURNY1");
	Patroller Cop(8, 5, ToChar("green"), "COP");
	Scene Level(16, 16);

	Cop.Construct(4, 2, 2, 2, 3);

	 Player.MainMenu = &MainMenu;
	Player Player(7, 7, 'p', "PLAYER");
	Enemy Enemy1(0, 0, 'e', "ENEMY");
	Rect Wall(3, 4, 6, 10, 'g', "WALL1");
	Level.AddActor(Player);
	Level.AddActor(Enemy1);
	Level.AddRect(Turny1);
	 Level.AddActor(Turny2);
	Level.AddRect(Wall);
	Level.AddActor(Button);
	Level.AddActor(Cop);
	Enemy1.moveChance[0] = 3;
	Cop.moveChance[0] = 3;
	 Level.DevMode = true;

	Timer StopWatch;
	double Total = 0;
	int Ticks = 1;
	double Highest = 0, Lowest = 1;

	DevLog MainLog("MainLog", "txt");

	while (GameRunning)
	{
		Level.Update();
		Level.Render();
		 std::cout << Player.CountNearby(Level) << std::endl;
		double temp = StopWatch.Lap();
		std::cout << "DeltaTime: " << temp << '\n';
		Total += temp;
		std::cout << "Average Time: " << (Total / Ticks) << '\n';
		if (Highest < temp)
			Highest = temp;
		if (Lowest > temp)
			Lowest = temp;
		std::cout << "Highest Time: " << Highest << '\n';
		std::cout << "Lowest Time: " << Lowest << '\n';
		std::cout << "Tick: " << Ticks << '\n';
		std::cout << "FPS: " << 1 / temp << '\n';
		std::cout << "Timer: " << StopWatch.GetTime() << '\n';
		MainLog.LOGLN("Your Mother");


		Player.Move(Level);
		Ticks++;
		Turny1.Rotate(1, Turny1.GetCenterX(), Turny1.GetCenterY());

		 Adds player collision to every rect in level
		 if(Level.RectCollision(Player))
		 	Player.SendBack();

		 Adds player collision to just one rect
		if (Wall.CheckCollision(Player))
			Player.SendBack();

		Enemy1.TurnRandom(true, true, true, true);
		if (Player.CheckCollision(Enemy1))
			GameRunning = false;

		if (Player.CheckCollision(Button))
		{
			Wall.corner1.x = Wall.corner1.x == 4 ? 3 : 4;
			 SaveGame();
		}

		Cop.Move(Player, Level);
		if (!Cop.Alert)
			Cop.MoveFoward(Level);
		if (Cop.position.y <= 2)
			Cop.direction = DOWN;
		else if (Cop.position.y >= 13)
			Cop.direction = UP;

		if (Level.RectCollision(Cop))
			Cop.SendBack();

		for (int Index = 0; Index < Level.dynamicActors.size(); Index++)
		{
			if (Level.RectCollision(Level.dynamicActors[Index]))
				Level.DestroyDynamicActor(Index);
		}


	}
	Level.Update();
	Level.Render(true);
	std::cout << "\033[31mYOU DIED";
	*/
	
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
