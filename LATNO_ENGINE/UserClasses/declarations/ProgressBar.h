#include "../../engine/declarations/Rendering/GL_Definitions.h"
#include "../../engine/declarations/Engine.h"

class ProgressBar : public Latno_Entities::AdvancedActor
{
	using AdvancedActor::AdvancedActor;
public:
	glm::vec2 scale;
	int amountHave;

	void Start() override
	{
		SetScale({ 0.1, 0.3 });

	}
	void Update(double deltaTime) override
	{

	}

};