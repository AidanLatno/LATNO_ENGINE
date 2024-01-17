#pragma once
#include "../../Entities/declarations/AdvancedActor.h"

namespace Latno
{
	/*
	* Class Name: PhysicsController
	* Purpose: Applying physics to game objects
	*/
	class PhysicsController : public Latno::Component
	{
	public:
		Actor* actorRef;
		float mass = 1;


		void ApplyGravity(Coords centerPoint, float pullForce = 1);
		void ApplyForce(Coords centerPoint, float pullForce = 1);
		void ApplyFloorGravity(float pullForce = 1);

		float CalcYValue(float xPoint);


	};
}