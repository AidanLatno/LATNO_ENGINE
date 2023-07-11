#pragma once

#include "../../engine/declarations/Rendering/GL_Definitions.h"
#include "Player.h"

namespace Latno
{
	class ProgressBarv2 : public AdvancedActor
	{
		using AdvancedActor::AdvancedActor;
	public:
		glm::vec2 scale;
		Actor* trashBin;
		Player* player;

		void Start() override
		{
			SetScale({ 0.2, 0.5 });
		}
		void Update(double deltaTime) override
		{
			float ySize = player->amountInBoat / 10;
			SetScale({ 0.1f, ySize });
		}

	};
}