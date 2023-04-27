#pragma once
#include "glm/glm.hpp"

#include "../../engine/declarations/Route.h"

#include <string>

class CollisionBox
{
public:
	enum CollisionType {
		AABB,
		RADIUS
	};

	CollisionType collisionType;
	CollisionBox(Coords pos, glm::vec2 _size, std::string _enum = "AABB");

	std::string name;
	Coords corner1;
	Coords corner2;
	bool isCollider = true;

	Coords position;
	glm::vec2 size;
	float radius;
	glm::vec2 topLeft;
	glm::vec2 botRight;

	bool CheckOverlap(CollisionBox rect) const;
	void Rotate(float turnAmount = 1, float h = 0, float k = 0, float angle = 90);
	bool CheckCollisions(CollisionBox other);
};