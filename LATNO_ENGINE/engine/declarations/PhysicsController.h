#pragma once
#include "Scene.h"
#include "../../Entities/declarations/AdvancedActor.h"

namespace Latno
{
	/*
	* Class Name: PhysicsController
	* Purpose: Applying physics to game objects
	*/
	class PhysicsController : public Latno::Component
	{

		AdvancedActor* actorRef;
		Scene* sceneRef;

		float xValue;
		float yValue;
		float slope;
		float bValue;

		float mass = 1;

		void UpdateInfo();

		void ApplyGravity(Coords centerPoint, float pullForce);

		float CalcYValue(float xPoint);


	};
}