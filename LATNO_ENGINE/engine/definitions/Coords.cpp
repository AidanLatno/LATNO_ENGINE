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

	Coords Coords::operator = (Coords obj)
	{
		x = obj.x;
		y = obj.y;
		return *this;
	}

	Coords Coords::operator + (Coords obj)
	{
		return Coords{ x + obj.x,y + obj.y };
	}
	Coords Coords::operator - (Coords obj)
	{
		return Coords{ x - obj.x,y - obj.y };
	}
	Coords Coords::operator * (Coords obj)
	{
		return Coords{ x * obj.x,y * obj.y };
	}
	Coords Coords::operator / (Coords obj)
	{
		return Coords{ x / obj.x,y / obj.y };
	}

	Coords Coords::operator += (Coords obj)
	{
		*this = *this + obj;
		return *this;
	}
	Coords Coords::operator -= (Coords obj)
	{
		*this = *this - obj;
		return *this;
	}
	Coords Coords::operator *= (Coords obj)
	{
		*this = *this * obj;
		return *this;
	}
	Coords Coords::operator /= (Coords obj)
	{
		*this = *this / obj;
		return *this;
	}
	Coords Coords::operator * (float obj)
	{
		return Coords{ x * obj,y * obj };
	}
	Coords Coords::operator / (float obj)
	{
		return Coords{ x / obj,y / obj };
	}
	Coords Coords::operator *= (float obj)
	{
		*this = *this * obj;
		return *this;
	}
	Coords Coords::operator /= (float obj)
	{
		*this = *this / obj;
		return *this;
	}

	bool Coords::IsEqual(Coords a) const
	{
		if (x == a.x && y == a.y)
			return true;
		return false;
	}
	Coords Coords::AddX(float Adder) const
	{
		return { x + Adder,y };
	}
	Coords Coords::AddY(float Adder) const
	{
		return { x,y + Adder };
	}
	Coords Coords::Add(float Adder1, float Adder2) const
	{
		return { x + Adder1,y + Adder2 };
	}
	void Coords::Rotate(float TurnAmount = 1, float h = 0, float k = 0, float Angle = 90)
	{
		Coords Temp = *this;
		Temp -= {h, k};
		for (int i = 0; i < TurnAmount; i++)
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