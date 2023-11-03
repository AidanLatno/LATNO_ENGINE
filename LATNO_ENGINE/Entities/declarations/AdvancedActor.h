#pragma once
#include "../../engine/declarations/PhysicsController.h"

namespace Latno {
	/*
	* Class Name: AdvancedActor
	* Purpose: An actor with extra features and functionality such as simple movement and rotation.
	*		   On top of this it has a reference to the current scene, allowing advanced actors to
	*		   manipulate the scene that they are within.
	* Parents: Actor -> Component -> Behavior
	* 
	* Variables:
	*	currentScene
	*		- Pointer to a scene
	*		- Meant to point to the current scene that is being rendered
	* 
	*	MoveForward(Scene &Scene, float deltaTime)
	*		- Moves self in the direction this actor is facing, accounting for the speed attribute
	*		- Does not allow actor to travel outside of the passed in scene
	*	MoveForward(int SizeX,int SizeY)
	*	MoveForward()
	*	TurnRight(float deg)
	*	TurnLeft(float deg)
	* 
	*/
	class AdvancedActor: public Actor
	{
		using Actor::Actor;
		public:
			Scene* currentScene;

			void MoveForward(Scene &Scene);
			void MoveForward(int SizeX,int SizeY);
			void MoveForward();

			void TurnRight(float deg);
			void TurnLeft(float deg);

	};
}