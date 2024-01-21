#include "../../engine/declarations/Engine.h"



class NextDayButton : public Latno::Button
{
	using Button::Button;
private:
	Latno::Scene* sceneRef;
public:
	void SetScene(Latno::Scene* scene);
	void OnHover() override;
	void OnPress() override;
	void OnRelease() override;
	void NotHover() override;
};