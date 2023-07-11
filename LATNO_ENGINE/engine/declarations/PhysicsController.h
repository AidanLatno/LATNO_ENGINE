#pragma once
#include "Scene.h"

namespace Latno
{
	class PhysicsController : public Latno::Component
	{
		Actor* attachedActor;
		Scene* mainScene;

		void UpdateInfo();

		void ApplyGravity();


	};
}