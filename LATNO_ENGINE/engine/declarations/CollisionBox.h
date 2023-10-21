#pragma once
#include "Coords.h"

namespace Latno
{
	/*
	* Class Name: CollisionBox
	* Purpose: Can detect collisions between itself and other collision boxes. This is not automatic, collision methods must be called.
	* 
	* Enums:
	*	CollisionType
	*		- AABB and RADIUS collisions
	*		- AABB is box collision that uses top left and bottom right points
	*		- RADIUS is circular collision (Not yet functional)
	* 
	* Variables:
	*	collisionType
	*		- Specifies type of collision
	*	position
	*		- position within the scene
	*	size
	*		- size of box in AABB collision (width,length)
	*	radius
	*		- Radius of the circle in the RADIUS collision type
	*	topLeft
	*		- Top left corner of the box in AABB collision
	*	botRight
	*		- Bottom right corner of the box in AABB collision
	* Methods:
	*	Rotate(float Angle, float h, float k, float Rotations)
	*		- Rotates this box by the given angle, around the point (h,k). Repeats this process for the amount provided by the Rotations parameter.
	*		- Default angle is 90, default point for (h,k) is (0,0) and rotations is set to 1.
	*	CheckCollision(CollisionBox other),(Coords point)
	*		- Returns true if this is colliding with the parameter
	*/
	class CollisionBox
	{
	public:
		enum CollisionType {
			AABB,
			RADIUS
		};

		CollisionType collisionType;
		CollisionBox(Coords pos, glm::vec2 _size, std::string _enum = "AABB");

		Coords position;
		glm::vec2 size;
		float radius;
		glm::vec2 topLeft;
		glm::vec2 botRight;

		void Rotate(float Angle, float h, float k, float Rotations);
		bool CheckCollision(CollisionBox other);
		bool CheckCollision(Coords point);
	};
}