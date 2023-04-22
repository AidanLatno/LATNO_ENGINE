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
	CollisionBox(int _x1, int _y1, int _x2, int _y2, std::string _name);
	CollisionBox(Coords _pos1, Coords _pos2, std::string _name);
	CollisionBox(Coords pos, glm::vec2 _size, std::string _enum);

	std::string name;
	Coords corner1;
	Coords corner2;
	bool isCollider = true;

	Coords position;
	glm::vec2 size;
	float radius;
	glm::vec2 topLeft;
	glm::vec2 botRight;

	bool CheckCollision(Coords point) const;
	bool CheckOverlap(CollisionBox rect) const;
	void SwapCheck();
	int GetCenterX() const;
	int GetCenterY() const;
	Coords GetCenter() const;
	void Rotate(int turnAmount = 1, int h = 0, int k = 0, int angle = 90);
	bool CheckCollisions(CollisionBox other);
};