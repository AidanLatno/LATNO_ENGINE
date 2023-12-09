#include "../declarations/PlayerExample.h"

void PlayerExample::Update()
{
	Animate(0.1f, spriteList);
	ManageInput(*currentScene);
}

void PlayerExample::Start()
{
	spriteList.push_back("resources/textures/idle/pos1.png");
	spriteList.push_back("resources/textures/idle/pos2.png");
	spriteList.push_back("resources/textures/idle/pos3.png");
	spriteList.push_back("resources/textures/idle/pos4.png");
	spriteList.push_back("resources/textures/idle/pos5.png");
	spriteList.push_back("resources/textures/idle/pos6.png");
	spriteList.push_back("resources/textures/idle/pos7.png");
	spriteList.push_back("resources/textures/idle/pos8.png");

	SetScale({ 2,2 });
}