#pragma once

#include "../../engine/declarations/Rendering/GL_Definitions.h"
#include "Player.h"

class ProgressBar : public Latno_Entities::AdvancedActor
{
	using AdvancedActor::AdvancedActor;
public:
	glm::vec2 scale;
	Player* player;

	void Start() override
	{
		SetScale({ 0.1, 0.3 });

	}
	void Update(double deltaTime) override
	{
		float ySize = 0.03 * player->amountInBoat;
		int changeOfYPos = 0;

		if (player->amountInBoat < player->carryingCapacity) {
			changeOfYPos = -5 + (int)(player->amountInBoat * 1.5);
			SetPos(Coords(player->GetPos().x + 32, player->GetPos().y + changeOfYPos));
			SetScale({ 0.1f, ySize });
		}
		else{
			SetPos(Coords(player->GetPos().x + 32, player->GetPos().y + 5 ));
		}
		
	}

};