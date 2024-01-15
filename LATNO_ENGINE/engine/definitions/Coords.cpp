#pragma once

#include "../declarations/Coords.h"
namespace Latno
{
	Coords::Coords()
	{
		x = 0;
		y = 0;
	}
	Coords::Coords(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	Coords::Coords(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	Coords::Coords(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
	

	Coords Coords::operator + (Coords obj) { return Coords{ x + obj.x,y + obj.y }; }
	Coords Coords::operator - (Coords obj) { return Coords{ x - obj.x,y - obj.y }; }
	Coords Coords::operator * (Coords obj) { return Coords{ x * obj.x,y * obj.y }; }
	Coords Coords::operator / (Coords obj) { return Coords{ x / obj.x,y / obj.y }; }

	bool Coords::operator != (Coords obj) { return (x != obj.x || y != obj.y); }
	bool Coords::operator == (Coords obj) { return (x == obj.x && y == obj.y); }
	Coords Coords::operator = (Coords obj) { x = obj.x; y = obj.y; return *this; }
	Coords Coords::operator += (Coords obj) { *this = *this + obj; return *this; }
	Coords Coords::operator -= (Coords obj) { *this = *this - obj; return *this; }
	Coords Coords::operator *= (Coords obj) { *this = *this * obj; return *this; }
	Coords Coords::operator /= (Coords obj) { *this = *this / obj; return *this; }

	Coords Coords::operator * (float obj) { return Coords{ x * obj,y * obj }; }
	Coords Coords::operator / (float obj) { return Coords{ x / obj,y / obj }; }
	Coords Coords::operator + (float obj) { return Coords{ x + obj,y + obj }; }
	Coords Coords::operator - (float obj) { return Coords{ x - obj,y - obj }; }

	bool Coords::operator != (float obj) { return (x != obj || y != obj); }
	bool Coords::operator == (float obj) { return (x == obj && y == obj); }
	Coords Coords::operator = (float obj) { x = obj; y = obj; return *this; }
	Coords Coords::operator *= (float obj) { *this = *this * obj; return *this; }
	Coords Coords::operator /= (float obj) { *this = *this / obj; return *this; }
	Coords Coords::operator += (float obj) { *this = *this + obj; return *this; }
	Coords Coords::operator -= (float obj) { *this = *this - obj; return *this; }

	Coords Coords::operator * (glm::vec2 obj) { return { x * obj.x,y * obj.y }; }
	Coords Coords::operator / (glm::vec2 obj) { return { x / obj.x,y / obj.y }; }
	Coords Coords::operator + (glm::vec2 obj) { return { x + obj.x,y + obj.y }; }
	Coords Coords::operator - (glm::vec2 obj) { return { x - obj.x,y - obj.y }; }

	bool Coords::operator != (glm::vec2 obj) { return (x != obj.x || y != obj.y); }
	bool Coords::operator == (glm::vec2 obj) { return (x == obj.x && y == obj.y); }
	Coords Coords::operator = (glm::vec2 obj) { x = obj.x; y = obj.y; return *this; }
	Coords Coords::operator *= (glm::vec2 obj) { *this = *this * obj; return *this; }
	Coords Coords::operator /= (glm::vec2 obj) { *this = *this / obj; return *this; }
	Coords Coords::operator += (glm::vec2 obj) { *this = *this + obj; return *this; }
	Coords Coords::operator -= (glm::vec2 obj) { *this = *this - obj; return *this; }

	bool Coords::IsEqual(Coords a) const
	{
		if (x == a.x && y == a.y)
			return true;
		return false;
	}
	void Coords::Rotate(float Angle = 90, float h = 0, float k = 0, float Rotations = 1)
	{
		Coords Temp = *this;
		Temp -= Coords(h, k);
		for (int i = 0; i < Rotations; i++)
		{
			x = (Temp.x * dCos(Angle) - Temp.y * dSin(Angle)) + h;
			y = (Temp.x * dSin(Angle) + Temp.y * dCos(Angle)) + k;
		}
	}

	double Coords::FindDistance(Coords a)
	{
		return sqrt(pow(abs(y - a.y), 2) + pow(abs(x - a.x), 2));
	}


	float Coords::dSin(float theta)
	{
		return sin(theta * 3.14159265359 / 180);
	}

	float Coords::dCos(float theta)
	{
		return cos(theta * 3.14159265359 / 180);
	}
}