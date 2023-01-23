#pragma once
#include "../../engine/declarations/Scene.h"

namespace Latno_Entities {
	class AdvancedActor: public Actor
	{
		using Actor::Actor;
		public:
			void SendBack();

			void MoveFoward(Scene &Scene,int Speed = 1);

			void MoveFoward(int Speed = 1);

			void MoveFoward(int SizeX,int SizeY,int Speed = 1);

			void TurnRight(int TurnAmount);
			void TurnLeft(int TurnAmount);
			void TurnRandom(bool Up = true,bool Right = true,bool Down = true,bool Left = true);
			bool IsNearby(Actor Actor,int Size) const;
			int CountNearby(Scene Scene, int Size);

	};
}