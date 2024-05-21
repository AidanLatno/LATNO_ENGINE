#include "../../engine/declarations/Engine.h"
#include "../../engine/declarations/InputManager.h"

class TopDownPlayer : public Latno::AdvancedActor
{
	using AdvancedActor::AdvancedActor;
private:
	std::string moverTag;
	void Movement();
	void Input();
public:
	std::string GetMoverTag() { return moverTag; }
	void SetMoverTag(std::string tag) { moverTag = tag; }
	std::vector<std::string> spriteList;
	std::vector<std::string> spriteListL;
	

	void Start() override
	{
		spriteList.push_back("resources/textures/idle/pos1.png");
		spriteList.push_back("resources/textures/idle/pos2.png");
		spriteList.push_back("resources/textures/idle/pos3.png");
		spriteList.push_back("resources/textures/idle/pos4.png");
		spriteList.push_back("resources/textures/idle/pos5.png");
		spriteList.push_back("resources/textures/idle/pos6.png");
		spriteList.push_back("resources/textures/idle/pos7.png");
		spriteList.push_back("resources/textures/idle/pos8.png");

		spriteListL.push_back("resources/textures/idle/pos1L.png");
		spriteListL.push_back("resources/textures/idle/pos2L.png");
		spriteListL.push_back("resources/textures/idle/pos3L.png");
		spriteListL.push_back("resources/textures/idle/pos4L.png");
		spriteListL.push_back("resources/textures/idle/pos5L.png");
		spriteListL.push_back("resources/textures/idle/pos6L.png");
		spriteListL.push_back("resources/textures/idle/pos7L.png");
		spriteListL.push_back("resources/textures/idle/pos8L.png");
	}

	void Update() override;
};