#pragma once
#include "../../Entities/declarations/Actor.h"
namespace Latno
{
	class Circle
	{
	public:
		Coords center;
		float radius;
		char ch;

		Circle(Coords _center, int _radius, char _ch);

		bool CheckCollision(Coords point);
	};
}