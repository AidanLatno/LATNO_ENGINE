#pragma once
#include <math.h>
#include "Timer.h"

struct Coords
{
	float x;
	float y;

	Coords();
	Coords(float _x, float _y);

	Coords operator = (Coords obj);

	Coords operator + (Coords obj);
	Coords operator - (Coords obj);
	Coords operator * (Coords obj);
	Coords operator / (Coords obj);

	Coords operator += (Coords obj);
	Coords operator -= (Coords obj);
	Coords operator *= (Coords obj);
	Coords operator /= (Coords obj);
	Coords operator * (float obj);
	Coords operator / (float obj);
	Coords operator *= (float obj);
	Coords operator /= (float obj);

	bool IsEqual(Coords a) const;
	Coords AddX(float Adder) const;
	Coords AddY(float Adder) const;
	Coords Add(float Adder1, float Adder2) const;
	void Rotate(float TurnAmount, float h, float k, float Angle);
	double FindDistance(Coords a);


	float dSin(float theta);
	
	float dCos(float theta);
};