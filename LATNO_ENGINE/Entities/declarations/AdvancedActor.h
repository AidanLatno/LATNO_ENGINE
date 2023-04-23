#pragma once
#include "../../engine/declarations/PhysicsController.h"

namespace Latno_Entities {
	class AdvancedActor: public Actor
	{
		using Actor::Actor;
		public:
			Scene* currentScene;

			void SendBack();

			void MoveForward(Scene &Scene, float deltaTime);

			void MoveForward(int Speed = 1);

			void MoveForward(int SizeX,int SizeY,int Speed = 1);

			void TurnRight(int TurnAmount);
			void TurnLeft(int TurnAmount);
			void TurnRandom(bool Up = true,bool Right = true,bool Down = true,bool Left = true);
			int CountNearby(Scene Scene, int Size);

	};
}