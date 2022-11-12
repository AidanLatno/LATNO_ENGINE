#include "../../engine/declarations/Engine.h"

class Circle
{
	public:
		Coords Center;
		float Radius;
		char ch;

		Circle(Coords _Center,int _Radius, char _ch);

		bool CheckCollision(Coords Point);
};