#pragma once

#include <string>
#include <math.h>

#include "../declarations/CollisionBox.h"
#include "../../engine/declarations/Coords.h"
#include "../../engine/declarations/Rendering/GL_Definitions.h"


CollisionBox::CollisionBox(int _x1, int _y1, int _x2, int _y2, std::string _Name)
{
	corner1.x = _x1;
	corner2.x = _x2;
	corner1.y = _y1;
	corner2.y = _y2;
	name = _Name;

	//LOGLN("Rect Named \"" + name + "\" was succesfully created with the coords: (" + std::to_string(corner1.x) + ", " + std::to_string(corner1.y) + "),(" + std::to_string(corner2.x) + ", " + std::to_string(corner2.y) + ")");
}

CollisionBox::CollisionBox(Coords _pos1, Coords _pos2, std::string _name)
{
	corner1 = _pos1;
	corner2 = _pos2;
	name = _name;
	//LOGLN("Rect Named \"" + name + "\" was succesfully created with the coords: (" + std::to_string(corner1.x) + ", " + std::to_string(corner1.y) + "),(" + std::to_string(corner2.x) + ", " + std::to_string(corner2.y) + ")");
}

CollisionBox::CollisionBox(Coords _pos, glm::vec2 _size, std::string _enum)
{
	if (size.x >= size.y)
		radius = size.x / 2;
	else if (size.y >= size.x)
		radius = size.y / 2;
	
		if (_enum == "AABB")
			collisionType = CollisionType::AABB;
	else if (_enum == "circ")
			collisionType = CollisionType::RADIUS;

	position = _pos;


	topLeft = { position.x - size.x / 2, position.y + size.y / 2 };
	botRight = { position.x + size.x / 2, position.y - size.y / 2 };

}


bool CollisionBox::CheckCollision(Coords point) const
{
	if (point.x >= corner1.x && point.x <= corner2.x && point.y >= corner1.y && point.y <= corner2.y)
		return true;
	return false;
}


bool CollisionBox::CheckOverlap(CollisionBox rect) const
{
	return false;
}

void CollisionBox::SwapCheck()
{
	if (corner1.x > corner2.x || corner1.y > corner2.y)
	{
		Coords temp = corner1;
		corner1 = corner2;
		corner2 = temp;
	}
}

int CollisionBox::GetCenterX() const
{
	return abs((corner1.x + corner2.x) / 2);
}

int CollisionBox::GetCenterY() const
{
	return abs((corner1.y + corner2.y) / 2);
}

Coords CollisionBox::GetCenter() const
{
	return { GetCenterX(), GetCenterY() };
}

void CollisionBox::Rotate(int turnAmount, int h, int k, int angle)
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

bool CollisionBox::CheckCollisions(CollisionBox other)
{
	//if (collisionType == CollisionType::AABB)
	//{

	topLeft = { position.x - size.x / 2, position.y + size.y / 2 };
	botRight = { position.x + size.x / 2, position.y - size.y / 2 };

	other.topLeft = { other.position.x - other.size.x / 2, other.position.y + other.size.y / 2 };
	other.botRight = { other.position.x + other.size.x / 2, other.position.y - other.size.y / 2 };

	if (topLeft.x > other.botRight.x || other.topLeft.x > botRight.x) {
		return false;
	}

	// If one rectangle is above the other
	if (topLeft.y < other.botRight.y || other.topLeft.y < botRight.y) {
		return false;
	}
	return true;

	//if (botLeft.x <= other.topRight.x && topRight.y >= other.botLeft.y)
	//	std::cout << "First check true\n\n";
	//else
	//	std::cout << "first false\n";
	//if (botLeft.y <= other.topRight.y && topRight.x >= other.botLeft.x)
	//	std::cout << "Second check true\n\n";

	//else
	//	std::cout << "second false\n";
	//	bool x = botLeft.x <= other.topRight.x && topRight.y <= other.botLeft.y;
	//	bool y = botLeft.y <= other.topRight.y && topRight.x >= other.botLeft.x;
	//	return x || y;
	//}

	if (collisionType == CollisionType::RADIUS)
	{

		glm::vec2 center(position.x + radius, position.y + radius);
		glm::vec2 half(other.size.x / 2.0f, other.size.y / 2.0f);
		glm::vec2 AABBCenter(other.position.x + half.x, other.position.y + half.y);
		glm::vec2 difference = center - AABBCenter;
		glm::vec2 clamp = glm::clamp(difference, -half, half);
		glm::vec2 closest = AABBCenter + clamp;
		difference = closest - center;
		return glm::length(difference) < radius;
	}

	return false;
}