#pragma once

#include "../declarations/Actor.h"

namespace Latno_Entities 
{
	Actor::Actor(int _x, int _y, char _ch, std::string _name)
	{
		position.x = _x;
		position.y = _y;
		ch = _ch;
		name = _name;
		preData.x = _x;
		preData.y = _y;
		//LOGLN("Actor named \"" + name + "\" was succesfully created with the coords: (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")");
	}

	Actor::Actor(Coords _Pos, char _ch, std::string _name)
	{
		position = _Pos;
		ch = _ch;
		name = _name;
		preData = _Pos;
		//LOGLN("Actor named \"" + name + "\" was succesfully created with the coords: (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")");
	}

	Actor::Actor()
	{
		position = {0,0};
		ch = '.';
		name = "UN-NAMED_ACTOR";
		//LOGLN("Actor named \"" + name + "\" was succesfully created with the coords: (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")");
	}

	void Actor::SetCoords(int x,int y)
	{
		preData = position;
		position.x = x;
		position.y = y;
	}

	void Actor::SetCoords(Coords Pos)
	{
		preData = position;
		position = Pos;
	}

	bool Actor::CheckCollision(Actor Actor) const
	{
		if(position.IsEqual(Actor.position))
			return true;
		return false;
	}

	bool Actor::CheckCollision(Coords Point) const
	{
		if(position.IsEqual(Point))
			return true;
		return false;
	}

	bool Actor::IsNearby(Actor Actor) const
	{
		int AX = Actor.position.x,
				AY = Actor.position.y,
				X = position.x,
				Y = position.y;
		if((AX == X || AX == X - 1 || AX == X + 1) && (AY == Y || AY == Y - 1 || AY == Y + 1))
			return true;
		return false;
	}

	bool Actor::IsNearby(Coords Point) const
	{
		int AX = Point.x,
				AY = Point.y,
				X = position.x,
				Y = position.y;
		if((AX == X || AX == X - 1 || AX == X + 1) && (AY == Y || AY == Y - 1 || AY == Y + 1))
			return true;
		return false;
	}


}