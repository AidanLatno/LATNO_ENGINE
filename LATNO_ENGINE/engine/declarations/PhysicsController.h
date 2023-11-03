#pragma once
#include "Scene.h"

namespace Latno
{
	/*
	* Class Name: PhysicsController
	* Purpose: Applying physics to game objects
	*/
	class PhysicsController : public Latno::Component
	{
		Actor* attachedActor;
		Scene* mainScene;

		void UpdateInfo();

		void ApplyGravity();


	};
}