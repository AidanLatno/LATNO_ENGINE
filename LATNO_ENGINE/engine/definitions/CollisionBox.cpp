#pragma once

#include <string>
#include <math.h>

#include "../declarations/CollisionBox.h"
#include "../declarations/Coords.h"
#include "../declarations/Rendering/GL_Definitions.h"


namespace Latno
{
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

	void CollisionBox::Rotate(float angle = 90, float h = 0, float k = 0, float Rotations = 1)
	{

		Coords temp1 = { 0,0 };
		Coords temp2 = { 0,0 };
		temp1 = topLeft;
		temp2 = botRight;

		temp1 -= Coords( h, k );
		temp2 -= Coords( h, k );

		for (int i = 0; i < Rotations; i++)
		{
			topLeft.x = (temp1.x * Coords().dCos(angle) - temp1.y * Coords().dSin(angle)) + h;
			topLeft.y = (temp1.x * Coords().dSin(angle) + temp1.y * Coords().dCos(angle)) + k;
			botRight.x = (temp2.x * Coords().dCos(angle) - temp2.y * Coords().dSin(angle)) + h;
			botRight.y = (temp2.x * Coords().dSin(angle) + temp2.y * Coords().dCos(angle)) + k;
		}
	}

	bool CollisionBox::CheckCollision(CollisionBox other)
	{
		//if (collisionType == CollisionType::AABB)
		//{

		topLeft = { position.x - (size.x / 2), position.y + (size.y / 2) };
		botRight = { position.x + (size.x / 2), position.y - (size.y / 2) };

		other.topLeft = { other.position.x - (other.size.x / 2), other.position.y + (other.size.y / 2) };
		other.botRight = { other.position.x + (other.size.x / 2), other.position.y - (other.size.y / 2) };

		if (topLeft.x > other.botRight.x || other.topLeft.x > botRight.x) {
			return false;
		}

		// If one rectangle is above the other
		if (topLeft.y < other.botRight.y || other.topLeft.y < botRight.y) {
			return false;
		}
		return true;

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

	bool CollisionBox::CheckCollision(Coords point) // Ehhh do later
	{
		return false; 
	}
}