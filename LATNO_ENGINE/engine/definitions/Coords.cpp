#pragma once

#include "Coords.h"

Coords::Coords()
{
	x = 0;
	y = 0;
}
Coords::Coords(int _x, int _y)
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
	return Coords{x + obj.x,y + obj.y};
}
Coords Coords::operator - (Coords obj)
{
	return Coords{x - obj.x,y - obj.y};
}
Coords Coords::operator * (Coords obj)
{
	return Coords{x * obj.x,y * obj.y};
}
Coords Coords::operator / (Coords obj)
{
	return Coords{x / obj.x,y / obj.y};
}
Coords Coords::operator % (Coords obj)
{
	return Coords{x % obj.x,y % obj.y};
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
Coords Coords::operator %= (Coords obj)
{
	*this = *this % obj;
	return *this;
}
Coords Coords::operator * (int obj)
{
	return Coords{x * obj,y * obj};
}
Coords Coords::operator / (int obj)
{
	return Coords{x / obj,y / obj};
}
Coords Coords::operator % (int obj)
{
	return Coords{x % obj,y % obj};
}
Coords Coords::operator *= (int obj)
{
	*this = *this * obj;
	return *this;
}
Coords Coords::operator /= (int obj)
{
	*this = *this / obj;
	return *this;
}
Coords Coords::operator %= (int obj)
{
	*this = *this % obj;
	return *this;
}

bool Coords::IsEqual(Coords a) const
{
	if(x == a.x && y == a.y)
		return true;
	return false;
}
Coords Coords::AddX(int Adder) const
{
	return {x + Adder,y};
}
Coords Coords::AddY(int Adder) const
{
	return {x,y + Adder};
}
Coords Coords::Add(int Adder1,int Adder2) const
{
	return {x + Adder1,y + Adder2};
}
void Coords::Rotate(int TurnAmount = 1,int h = 0,int k = 0,int Angle = 90)
{
	Coords Temp = *this;
	Temp-={h,k};
	for(int i = 0; i < TurnAmount; i++)
	{
		x = (Temp.x * dCos(Angle) - Temp.y * dSin(Angle)) + h;
		y = (Temp.x * dSin(Angle) + Temp.y * dCos(Angle)) + k;
	}
}


int Coords::dSin(int theta)
{
	return (int)(sin(theta * 3.14159265359/180));
}

int Coords::dCos(int theta)
{
	return (int)(cos(theta * 3.14159265359/180));
}