#include "../declarations/Application.h"


std::string Application::GetNumPath(int num)
{
	switch (num)
	{
	case 0:
		return "resources/textures/0.png";
		break;
	case 1:
		return "resources/textures/1.png";
		break;
	case 2:
		return "resources/textures/2.png";
		break;
	case 3:
		return "resources/textures/3.png";
		break;
	case 4:
		return "resources/textures/4.png";
		break;
	case 5:
		return "resources/textures/5.png";
		break;
	case 6:
		return "resources/textures/6.png";
		break;
	case 7:
		return "resources/textures/7.png";
		break;
	case 8:
		return "resources/textures/8.png";
		break;
	case 9:
		return "resources/textures/9.png";
		break;
	default:
		return "resources/textures/0.png";
		break;

	}
}

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
	Latno_Entities::Actor num4(310, 520, "resources/textures/0.png");
	Latno_Entities::Actor heart1(820, 520, "resources/textures/full_heart.png");
	Latno_Entities::Actor heart2(870, 520, "resources/textures/full_heart.png");
	Latno_Entities::Actor heart3(920, 520, "resources/textures/full_heart.png");

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
	num4.SetScale({ 0.5, 0.25 });

	heart1.SetScale({ 0.5, 0.25 });
	heart2.SetScale({ 0.5, 0.25 });
	heart3.SetScale({ 0.5, 0.25 });

	num4.SetScale({ 0.5, 0.25 });
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
	num4Ptr = &num4;
	scorePtr = &score;
	insPtr = &ins;
	heart1ptr = &heart1;
	heart2ptr = &heart2;
	heart3ptr = &heart3;

	level.AddActor(bin);
	level.AddActor(water);
	level.AddActor(land);
	level.AddActor(player);
	level.AddActor(progressBar);
	level.AddActor(num1);
	level.AddActor(num2);
	level.AddActor(num3);
	level.AddActor(num4);
	level.AddActor(heart1);
	level.AddActor(heart2);
	level.AddActor(heart3);
	level.AddActor(score);
	level.AddActor(ins);

	Load();


}

void Application::Run()
{
	DevLog AppLog("AppLog");
	Timer DeltaCalc;
	float prevDeltaTime = 0;

	float timer;
	float difficultyMod = 0;

	while (true)
	{
		// vv RENDERING vv
		ImGui_ImplGlfwGL3_NewFrame();
		levelPtr->Render();

		// vv TICK vv
		if (!Tick(prevDeltaTime))
			return;

		// vv SUMMON TRASH vv
		if (countDown <= 0)
		{
			levelPtr->DestroyActor(insPtr);
			countDown = 1 - difficultyMod;
			int ranNum = rand() % 8;
			
			if (ranNum < 6)
			{
				int ran = rand() % 3;
				
				Latno_Entities::Actor t(rand() % (WINDOW_LENGTH - 220) + 160, 500, TrashSprites[ran]);
				
				if(ran == 2)
					t.SetScale({0.5, 0.4});


				t.AddTag("trash");
				
				levelPtr->AddDynamicActor(t);
				
			}
			else if (ranNum == 7)
			{
				Latno_Entities::Actor t(rand() % (WINDOW_LENGTH - 220) + 160, 500, "resources/textures/fish1.png");
				t.AddTag("fish");
				t.SetScale({ 0.5,0.5 });
				levelPtr->AddDynamicActor(t);
			}
			else
			{
				Latno_Entities::Actor t(rand() % (WINDOW_LENGTH - 220) + 160, 500, "resources/textures/fish2.png");
				t.AddTag("fish");

				t.SetScale({ 0.5,0.5 });
				levelPtr->AddDynamicActor(t);
			}
		}
		// ^^ SUMMON TRASH ^^

		// vv DYNAMIC ACTOR LOGIC vv
		for (int i = 0; i < levelPtr->dynamicActors.size(); i++)
		{
			if (!levelPtr->dynamicActors[i].IfHasTag("DEATH"))
				levelPtr->dynamicActors[i].SetPos({ levelPtr->dynamicActors[i].GetPos().x, levelPtr->dynamicActors[i].GetPos().y - (100 * prevDeltaTime) });
			if (levelPtr->dynamicActors[i].IfHasTag("trash"))
			{
				if (levelPtr->dynamicActors[i].GetPos().y < - 5)
				{
					levelPtr->DestroyDynamicActor(i);
					i--;
					Lives--;
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
					for (int i = 0; i < playerPtr->amountInBoat; i++)
					{/*
						int x = rand() % (playerPtr->GetPos().x - 2) + (playerPtr->GetPos().x + 2);
						int y = rand() % (playerPtr->GetPos().y - 2) + (playerPtr->GetPos().y + 2);*/

						int x = playerPtr->GetPos().x + (rand() % 90-45);
						int y = playerPtr->GetPos().y - (rand() % 20 + 40);
						Latno_Entities::Actor t(x, y, TrashSprites[rand() % 2]);
						t.AddTag("trash");
						levelPtr->AddDynamicActor(t);

					}
					playerPtr->amountInBoat = 0;



				}
			}
		}
		// ^^ DYNAMIC ACTOR LOGIC ^^

		// vv HEART TEXTURE SWAPPING vv
		
		if (Lives == 2)
			heart1ptr->SwapTexture("resources/textures/empty_heart.png");
		if (Lives == 1)
			heart2ptr->SwapTexture("resources/textures/empty_heart.png");
		if (Lives == 0)
			heart3ptr->SwapTexture("resources/textures/empty_heart.png");


		// ^^ HEART TEXTURE SWAPPING ^^


		// vv BOAT TEXTURE SWAPPING vv
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
		// ^^ BOAT TEXTURE SWAPPING ^^

		// vv BIN COLLECTION vv
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
		// ^^ BIN COLLECTION ^^

		// vv SCORE COUNTER vv
		int m = playerPtr->score;
		int numArray[4];

		for (int i = 3; i >= 0; i--) {
			numArray[i] = m % 10;
			m /= 10;
		}

		num1Ptr->SwapTexture(GetNumPath(numArray[0]));
		num2Ptr->SwapTexture(GetNumPath(numArray[1]));
		num3Ptr->SwapTexture(GetNumPath(numArray[2]));
		num4Ptr->SwapTexture(GetNumPath(numArray[3]));

		// ^^ SCORE COUNTER ^^

		// vv LOSE DETECTION vv
		if (Lives <= 0)
		{
			Latno_Entities::Actor diedScreen(475, 275, "resources/textures/death.png");
			diedScreen.AddTag("DEATH");
			diedScreen.SetScale({ 9,3 });
			levelPtr->AddActor(diedScreen);
			levelPtr->Render();
			break;
		}
		// ^^ LOSE DETECTION ^^

		prevDeltaTime = DeltaCalc.GetTime();
		DeltaCalc.Reset();

		ImGui::Render();

		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	Renderer render;

	DevLog::LOGLN("Score: " + std::to_string(playerPtr->score), "ScoreLog");

	while (!(glfwGetKey(window,GLFW_KEY_ENTER) == GLFW_PRESS))
	{
		render.AddSprite(new Sprite(glm::vec3( 475, 275,0 ), glm::vec2( 9,3 ), "resources/textures/death.png", "AABB"));
		render.RenderSprites(window);

		glfwSwapBuffers(window);
		glfwPollEvents(); // idk man
	}
}
