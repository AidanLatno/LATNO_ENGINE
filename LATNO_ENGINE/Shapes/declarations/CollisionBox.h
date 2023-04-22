#pragma once

#include "../../Engine/declarations/Window.h"

#include <string>

class CollisionBox
{
public:
	CollisionBox(int _x1, int _y1, int _x2, int _y2, char _ch, std::string _name);
	CollisionBox(Coords _pos1, Coords _pos2, char _ch, std::string _name);

	std::string name;
	Coords corner1;
	Coords corner2;
	bool isCollider = true;

	bool CheckCollision(Latno_Entities::Actor actor) const;
	bool CheckCollision(Coords point) const;
	bool CheckOverlap(CollisionBox rect) const;
	void SwapCheck();
	int GetCenterX() const;
	int GetCenterY() const;
	Coords GetCenter() const;
	void Rotate(int turnAmount = 1, int h = 0, int k = 0, int angle = 90);
};