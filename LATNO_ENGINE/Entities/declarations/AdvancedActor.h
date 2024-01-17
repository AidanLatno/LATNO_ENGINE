#pragma once
#include "../../engine/declarations/Scene.h"

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
	*	MoveForward(Scene &Scene)
	*		- Moves self in the direction this actor is facing, accounting for the speed attribute
	*		- Does not allow actor to travel outside of the passed in scene
	*	MoveForward(int SizeX,int SizeY)
	*		- Moves self in the direction this actor is facing, accounting for the speed attribute
	*		- Does not allow actor to travel outside of the given sizes
	*	MoveForward()
	*		- Moves self in the direction this actor is facing, accounting for the speed attribute
	*	TurnRight(float deg)
	*		- Turns the actors direction to the right (uses degrees NOT radians)
	*	TurnLeft(float deg)
	*		- Turns the actors direction to the left (uses degrees NOT radians)
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