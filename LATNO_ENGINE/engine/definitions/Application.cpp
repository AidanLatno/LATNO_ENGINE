#include "../declarations/Application.h"

Application::~Application() 
{
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
}

void Application::BehaviorTick(double deltaTime)
{
	for (int i = 0; i < Latno::BehaviorList.size(); i++)
	{
		Latno::BehaviorList[i]->Update(deltaTime);
	}
}
void Application::BehaviorLoad()
{
	for (int i = 0; i < Latno::BehaviorList.size(); i++)
	{
		Latno::BehaviorList[i]->Start();
	}
}
void Application::Load()
{
	BehaviorLoad();
	DevLog::LOGLN("App Load Finished", "EngineLog");

	Run();

}
bool Application::Tick(double deltaTime)
{
	BehaviorTick(deltaTime);

	countDown -= 1 * deltaTime;

	binCountDown -= 1 * deltaTime;
	
	return true;
}

void Application::Startup(GLFWwindow* _window)
{
	window = _window;
	DevLog::CLEAR("EngineLog");
	DevLog::CLEAR("GL_ERROR_LOG");
	srand(time(NULL));

	Scene level(WINDOW_LENGTH, WINDOW_HEIGHT, window);

	Player player(475, 50, "resources/textures/boat1.png");
	Latno_Entities::Actor land(475, 275, "resources/textures/land.png");
	Latno_Entities::Actor water(475, 275, "resources/textures/water.png");

	Latno_Entities::Actor bin(800, 80, "None");

	Latno_Entities::Actor score(80, 520, "resources/textures/score.png");
	Latno_Entities::Actor num1(190, 520, "resources/textures/0.png");
	Latno_Entities::Actor num2(230, 520, "resources/textures/0.png");
	Latno_Entities::Actor num3(270, 520, "resources/textures/0.png");
	Latno_Entities::Actor ins(475, 275, "resources/textures/instructions.png");

	player.AddTag("player");

	ProgressBar progressBar(485, 57.5, "resources/textures/greenBar.jpg");


	progressBar.player = &player;


	bin.SetScale({ 1,0.5 });
	water.SetScale({ 7, 5.5 });
	land.SetScale({ 10, 5.5 });
	player.SetScale({ 0.5, 0.5f });
	ins.SetScale({ 9, 3 });

	num1.SetScale({  0.5, 0.25 });
	num2.SetScale({  0.5, 0.25 });
	num3.SetScale({  0.5, 0.25 });
	score.SetScale({ 1.8, 0.4});

	player.speed = 400;

	player.currentScene = &level;
	progressBar.currentScene = &level;
	

	waterPtr = &water;
	backgroundPtr = &land;
	playerPtr = &player;
	levelPtr = &level;
	barPtr = &progressBar;
	binPtr = &bin;
	num1Ptr = &num1;
	num2Ptr = &num2;
	num3Ptr = &num3;
	scorePtr = &score;
	insPtr = &ins;

	level.AddActor(bin);
	level.AddActor(water);
	level.AddActor(land);
	level.AddActor(player);
	level.AddActor(progressBar);
	level.AddActor(num1);
	level.AddActor(num2);
	level.AddActor(num3);
	level.AddActor(score);
	level.AddActor(ins);

	Load();


}

void Application::Run()
{
	DevLog AppLog("AppLog");
	Timer DeltaCalc;
	double prevDeltaTime = 0;

	float timer;
	float difficultyMod = 0;

	while (true)
	{
		ImGui_ImplGlfwGL3_NewFrame();
		levelPtr->Render();

		if (!Tick(prevDeltaTime))
			return;

		if (countDown <= 0) {
			levelPtr->DestroyActor(insPtr);
			countDown = 1.3 - difficultyMod;
			int ranNum = rand() % 8;
			if (ranNum < 6)
			{
				Latno_Entities::Actor t(rand() % (WINDOW_LENGTH - 200) + 160, 500, TrashSprites[rand() % 2]);
				t.AddTag("trash");
				levelPtr->AddDynamicActor(t);
			}
			else if (ranNum == 7)
			{
				Latno_Entities::Actor t(rand() % (WINDOW_LENGTH - 200) + 160, 500, "resources/textures/fish1.png");
				t.AddTag("fish");
				t.SetScale({ 0.5,0.5 });
				levelPtr->AddDynamicActor(t);
			}
			else
			{
				Latno_Entities::Actor t(rand() % (WINDOW_LENGTH - 200) + 160, 500, "resources/textures/fish2.png");
				t.AddTag("fish");

				t.SetScale({ 0.5,0.5 });
				levelPtr->AddDynamicActor(t);
			}
		}

		// Trash logic
		for (int i = 0; i < levelPtr->dynamicActors.size(); i++)
		{
			if (!levelPtr->dynamicActors[i].IfHasTag("DEATH"))
				levelPtr->dynamicActors[i].SetPos({ levelPtr->dynamicActors[i].GetPos().x, levelPtr->dynamicActors[i].GetPos().y - 1 });
			if (levelPtr->dynamicActors[i].IfHasTag("trash"))
			{
				if (levelPtr->dynamicActors[i].GetPos().y < -5)
				{
					levelPtr->DestroyDynamicActor(i);
					i--;
					passed++;
					continue;
				}

				if (levelPtr->dynamicActors[i].collisionBox->CheckCollisions(*playerPtr->collisionBox) && playerPtr->amountInBoat < playerPtr->carryingCapacity)
				{
					levelPtr->DestroyDynamicActor(i);
					playerPtr->amountInBoat++;
					i--;


				}
			}
			else if (levelPtr->dynamicActors[i].IfHasTag("fish"))
			{
				if (levelPtr->dynamicActors[i].collisionBox->CheckCollisions(*playerPtr->collisionBox))
				{
					/*for (int i = 0; i < playerPtr->amountInBoat; i++)
					{
						int x = rand() % (playerPtr->GetPos().x - 2) + (playerPtr->GetPos().x + 2);
						int y = rand() % (playerPtr->GetPos().y - 2) + (playerPtr->GetPos().y + 2);
						Latno_Entities::Actor t(x, y, TrashSprites[rand() % 2]);
						t.AddTag("trash");
						levelPtr->AddDynamicActor(t);

					}*/
					playerPtr->amountInBoat = 0;



				}
			}
		}

		if (playerPtr->amountInBoat < playerPtr->carryingCapacity)
			barPtr->SwapTexture("resources/textures/greenBar.jpg");
		else
			barPtr->SwapTexture("resources/textures/redBar.png");

		switch (playerPtr->amountInBoat)
		{
		case 1:
		case 2:
		case 3:
			playerPtr->SwapTexture("resources/textures/boat2.png");
			break;
		case 4:
		case 5:
		case 6:
			playerPtr->SwapTexture("resources/textures/boat3.png");
			break;
		case 7:
		case 8:
		case 9:
			playerPtr->SwapTexture("resources/textures/boat4.png");
			break;
		case 10:
			playerPtr->SwapTexture("resources/textures/boat5.png");
			break;
		default:
			playerPtr->SwapTexture("resources/textures/boat1.png");
			break;


		}


		if (binCountDown <= 0)
		{
			binCountDown = 0.2;
			if (playerPtr->collisionBox->CheckCollisions(*binPtr->collisionBox))
			{

				if (playerPtr->amountInBoat > 0)
				{
					playerPtr->score += 5;
					playerPtr->amountInBoat--;
				}

			}
		}




		int m = playerPtr->score;
		int numArray[3];

		for (int i = 2; i >= 0; i--) {
			numArray[i] = m % 10;
			m /= 10;
		}
		switch (numArray[0])
		{
		case 0:
			num1Ptr->SwapTexture("resources/textures/0.png");
			break;
		case 1:
			num1Ptr->SwapTexture("resources/textures/1.png");
			break;
		case 2:
			num1Ptr->SwapTexture("resources/textures/2.png");
			break;
		case 3:
			num1Ptr->SwapTexture("resources/textures/3.png");
			break;
		case 4:
			num1Ptr->SwapTexture("resources/textures/4.png");
			break;
		case 5:
			num1Ptr->SwapTexture("resources/textures/5.png");
			break;
		case 6:
			num1Ptr->SwapTexture("resources/textures/6.png");
			break;
		case 7:
			num1Ptr->SwapTexture("resources/textures/7.png");
			break;
		case 8:
			num1Ptr->SwapTexture("resources/textures/8.png");
			break;
		case 9:
			num1Ptr->SwapTexture("resources/textures/8.png");
			break;
		default:
			num1Ptr->SwapTexture("resources/textures/0.png");
			break;

		}

		switch (numArray[1])
		{
		case 0:
			num2Ptr->SwapTexture("resources/textures/0.png");
			break;
		case 1:
			num2Ptr->SwapTexture("resources/textures/1.png");
			break;
		case 2:
			num2Ptr->SwapTexture("resources/textures/2.png");
			break;
		case 3:
			num2Ptr->SwapTexture("resources/textures/3.png");
			break;
		case 4:
			num2Ptr->SwapTexture("resources/textures/4.png");
			break;
		case 5:
			num2Ptr->SwapTexture("resources/textures/5.png");
			break;
		case 6:
			num2Ptr->SwapTexture("resources/textures/6.png");
			break;
		case 7:
			num2Ptr->SwapTexture("resources/textures/7.png");
			break;
		case 8:
			num2Ptr->SwapTexture("resources/textures/8.png");
			break;
		case 9:
			num2Ptr->SwapTexture("resources/textures/8.png");
			break;
		default:
			num2Ptr->SwapTexture("resources/textures/0.png");
			break;

		}

		switch (numArray[2])
		{
		case 0:
			num3Ptr->SwapTexture("resources/textures/0.png");
			break;
		case 1:
			num3Ptr->SwapTexture("resources/textures/1.png");
			break;
		case 2:
			num3Ptr->SwapTexture("resources/textures/2.png");
			break;
		case 3:
			num3Ptr->SwapTexture("resources/textures/3.png");
			break;
		case 4:
			num3Ptr->SwapTexture("resources/textures/4.png");
			break;
		case 5:
			num3Ptr->SwapTexture("resources/textures/5.png");
			break;
		case 6:
			num3Ptr->SwapTexture("resources/textures/6.png");
			break;
		case 7:
			num3Ptr->SwapTexture("resources/textures/7.png");
			break;
		case 8:
			num3Ptr->SwapTexture("resources/textures/8.png");
			break;
		case 9:
			num3Ptr->SwapTexture("resources/textures/8.png");
			break;
		default:
			num3Ptr->SwapTexture("resources/textures/0.png");
			break;

		}

		if (passed >= 3)
		{
			Latno_Entities::Actor diedScreen(475, 275, "resources/textures/death.png");
			diedScreen.AddTag("DEATH");
			diedScreen.SetScale({ 9,3 });
			levelPtr->AddActor(diedScreen);
			levelPtr->Render();
			break;
		}

		prevDeltaTime = DeltaCalc.GetTime();
		DeltaCalc.Reset();

		ImGui::Render();

		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
		glfwPollEvents(); // idk man

	}
	Renderer render;

	render.AddSprite(new Sprite(glm::vec3( 475, 275,0 ), glm::vec2( 9,3 ), "resources/textures/death.png", "AABB"));
	render.RenderSprites(window);

	while (true);
}
