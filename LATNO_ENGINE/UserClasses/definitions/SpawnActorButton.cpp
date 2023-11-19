#include "../declarations/SpawnActorButton.h"

namespace Latno
{
	void SpawnActorButton::SetScene(Scene* scene)
	{
		referenceScene = scene;
	}
	void SpawnActorButton::OnHover()
	{
		SetScale({ 1.1,1.1 });
	}

	void SpawnActorButton::OnPress()
	{
		SetScale({ 0.9,0.9 });
	}

	void SpawnActorButton::OnRelease()
	{
		SetScale({ 1,1 });
		referenceScene->AddDynamicActor(Actor({ (float)(rand() % WINDOW_LENGTH), (float)(rand() % WINDOW_HEIGHT) }, "resources/textures/person.png"));
	}
	void SpawnActorButton::NotHover()
	{
		SetScale({ 1,1 });
	}
}
