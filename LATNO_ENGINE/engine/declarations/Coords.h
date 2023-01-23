#pragma once
#include <math.h>
#include "Timer.h"

struct Coords
{
	int x;
	int y;

	Coords();
	Coords(int _x, int _y);

	Coords operator = (Coords obj);

	Coords operator + (Coords obj);
	Coords operator - (Coords obj);
	Coords operator * (Coords obj);
	Coords operator / (Coords obj);
	Coords operator % (Coords obj);

	Coords operator += (Coords obj);
	Coords operator -= (Coords obj);
	Coords operator *= (Coords obj);
	Coords operator /= (Coords obj);
	Coords operator %= (Coords obj);
	Coords operator * (int obj);
	Coords operator / (int obj);
	Coords operator % (int obj);
	Coords operator *= (int obj);
	Coords operator /= (int obj);
	Coords operator %= (int obj);

	bool IsEqual(Coords a) const;
	Coords AddX(int Adder) const;
	Coords AddY(int Adder) const;
	Coords Add(int Adder1,int Adder2) const;
	void Rotate(int TurnAmount,int h,int k,int Angle);


	int dSin(int theta);
	
	int dCos(int theta);
};