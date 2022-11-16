#pragma once

#include <string>
#include <math.h>

#include "../declarations/Rect.h"
#include "../../engine/declarations/Coords.h"


Rect::Rect(int _x1, int _y1, int _x2, int _y2, char _ch, std::string _Name)
{
	corner1.x = _x1;
	corner2.x = _x2;
	corner1.y = _y1;
	corner2.y = _y2;
	ch = _ch;
	name = _Name;
	//LOGLN("Rect Named \"" + name + "\" was succesfully created with the coords: (" + std::to_string(corner1.x) + ", " + std::to_string(corner1.y) + "),(" + std::to_string(corner2.x) + ", " + std::to_string(corner2.y) + ")");
}

Rect::Rect(Coords _pos1, Coords _pos2, char _ch, std::string _name)
{
	corner1 = _pos1;
	corner2 = _pos2;
	ch = _ch;
	name = _name;
	//LOGLN("Rect Named \"" + name + "\" was succesfully created with the coords: (" + std::to_string(corner1.x) + ", " + std::to_string(corner1.y) + "),(" + std::to_string(corner2.x) + ", " + std::to_string(corner2.y) + ")");
}

bool Rect::CheckCollision(Latno_Entities::Actor actor) const
{
	if (actor.position.x >= corner1.x && actor.position.x <= corner2.x && actor.position.y >= corner1.y && actor.position.y <= corner2.y)
		return true;
	return false;
}

bool Rect::CheckCollision(Coords point) const
{
	if (point.x >= corner1.x && point.x <= corner2.x && point.y >= corner1.y && point.y <= corner2.y)
		return true;
	return false;
}

void Rect::SwapCheck()
{
	if (corner1.x > corner2.x || corner1.y > corner2.y)
	{
		Coords temp = corner1;
		corner1 = corner2;
		corner2 = temp;
	}
}

int Rect::GetCenterX()
{
	return abs((corner1.x + corner2.x) / 2);
}

int Rect::GetCenterY()
{
	return abs((corner1.y + corner2.y) / 2);
}

Coords Rect::GetCenter()
{
	return { GetCenterX(), GetCenterY() };
}

void Rect::Rotate(int turnAmount, int h, int k, int angle)
{
	Coords temp1 = this->corner1;
	Coords temp2 = this->corner2;
	temp1 -= { h, k };
	temp2 -= { h, k };

	for (int i = 0; i < turnAmount; i++)
	{
		corner1.x = (temp1.x * Coords().dCos(angle) - temp1.y * Coords().dSin(angle)) + h;
		corner1.y = (temp1.x * Coords().dSin(angle) + temp1.y * Coords().dCos(angle)) + k;
		corner2.x = (temp2.x * Coords().dCos(angle) - temp2.y * Coords().dSin(angle)) + h;
		corner2.y = (temp2.x * Coords().dSin(angle) + temp2.y * Coords().dCos(angle)) + k;
	}
	SwapCheck();
}
