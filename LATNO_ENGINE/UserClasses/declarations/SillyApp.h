#include "../../engine/declarations/Application.h"


class SillyApp : public Latno::Application
{
private:

public:
	Player* player;
	Latno::Scene* game;
	Latno::Actor* background;

	void Load() override;
	bool Tick() override;
	void End() override;
};