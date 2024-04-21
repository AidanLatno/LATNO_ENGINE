#include "../../engine/declarations/Engine.h"

class Player : public Latno::AdvancedActor
{
	using AdvancedActor::AdvancedActor;
private:
	std::string moverTag;
	void Movement();
	void Input();
public:
	std::string GetMoverTag() { return moverTag; }
	void SetMoverTag(std::string tag) { moverTag = tag; }

	

	void Update() override
	{
		Input();
	}
};