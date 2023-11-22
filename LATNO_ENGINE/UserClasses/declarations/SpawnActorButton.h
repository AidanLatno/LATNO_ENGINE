#pragma once
#include "../../engine/declarations/Engine.h"
namespace Latno
{
	class SpawnActorButton : public Button
	{
	using Button::Button;
	private:
		Scene* referenceScene;
	public:
		void SetScene(Scene* scene);

		void OnHover() override;
		void OnPress() override;
		void OnRelease() override;
		void NotHover() override;
	};
}
