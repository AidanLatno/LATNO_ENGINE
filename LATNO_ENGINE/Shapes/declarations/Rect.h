#pragma once

#include "../../Entities/declarations/Actor.h"
#include <string>

class Rect
{
	public:
		Rect(int _x1, int _y1, int _x2, int _y2, char _ch, std::string _name);
		Rect(Coords _pos1, Coords _pos2, char _ch, std::string _name);

		char ch;
		std::string name;
		Coords corner1;
		Coords corner2;

		bool CheckCollision(Latno_Entities::Actor actor) const;
		bool CheckCollision(Coords point) const;
		void SwapCheck();
		int GetCenterX();
		int GetCenterY();
		Coords GetCenter();
		void Rotate(int turnAmount = 1, int h = 0, int k = 0, int angle = 90);
};