#include "../declarations/NextDayButton.h"

void NextDayButton::SetScene(Latno::Scene* scene)
{
	sceneRef = scene;
}
void NextDayButton::OnHover()
{
	SetScale({ 1.1,1.1 });
	for (Actor& a : sceneRef->dynamicActors)
	{
		if (a.IfHasTag("NextText"))
		{
			a.SetScale({ 0.6,0.6 });
		}
	}
}

void NextDayButton::OnPress()
{
	SetScale({ 0.9,0.9 });
	for (Actor& a : sceneRef->dynamicActors)
	{
		if (a.IfHasTag("NextText"))
		{
			a.SetScale({ 0.4,0.4 });
		}
	}
}

void NextDayButton::OnRelease()
{
	SetScale({ 1,1 });
	for (Actor& a : sceneRef->dynamicActors)
	{
		if (a.IfHasTag("NextText"))
		{
			a.SetScale({ 0.5,0.5 });
		}
	}
}
void NextDayButton::NotHover()
{
	SetScale({ 1,1 });
	for (Actor& a : sceneRef->dynamicActors)
	{
		if (a.IfHasTag("NextText"))
		{
			a.SetScale({ 0.5,0.5 });
		}
	}
}