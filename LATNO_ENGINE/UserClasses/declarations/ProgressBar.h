#include "../../engine/declarations/Rendering/GL_Definitions.h"
#include "../../engine/declarations/Engine.h"

class ProgressBar : public Latno_Entities::AdvancedActor
{
	using AdvancedActor::AdvancedActor;
public:
	glm::vec2 scale;


	void Start() override
	{
		Latno_Entities::Actor progressBar(485, 50, "resources/textures/redBar.png");
		progressBar.SetScale({ 0.1, 0.25 });

	}
	void Update(double deltaTime) override
	{

	}

};