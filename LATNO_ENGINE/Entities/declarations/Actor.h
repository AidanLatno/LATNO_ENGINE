#pragma once
#include "../../engine/declarations/Rendering/Renderer.h"
#include "../../engine/declarations/CollisionBox.h"


namespace Latno
{
	/*
	* Class Name: Actor
	* Purpose: An actor is an object that exist within the game world (scene). An actor can be anything from
	*		   a simple collision box to a wall to a player.
	* Parents: Component -> Behavior
	* 
	* Constructors:
	*	Actor(float _x, float _y,std::string SpritePath)
	*		- 
	*	Actor(Coords _Pos, std::string SpritePath)
	*	Actor(float _x, float _y, glm::vec2 _scale, std::string SpritePath)
	*
	*	Actor();
	* 
	* Variables:
	*	position
	*		- Coords, that contains the position of the actor in the world
	*	preData
	*		- Coords, meant to store the previous location of the actor to undo movement
	*	scale
	*		- glm::vec2, scales the size of the actor's sprite and collision
	*	sprite
	*		- Contains the image of the actor to be rendered
	*	collisionBox
	*		- used for the actor's collision
	*	direction
	*		- Coords, contains a 2d vector that points in a direction
	*	speed
	*		- used for movement speed (if needed)
	* Methods:
	*	CheckCollision(Actor Actor)
	*		- Returns true if parameter actor is colliding with this
	*	CheckCollision(Coords Point)
	*		- Returns true if parameter actor is within this
	*	SwapTexture(string path)
	*		- Changes the texture of the actor to the file specified
	*	GetPos()
	*		- Returns the position value
	*	SetPos(Coords _pos)
	*		- Sets the position value to parameter
	*	SetSpriteScale(float x, float y)
	*		- Changes the scale of the sprite
	*		- Private (Gets used by SetScale())
	*	SetCollisionSize(glm::vec2 scale)
	*		- Sets scale for collisionBox
	*	SetScale(glm::vec2 _scale)
	*		- Sets scale for actor as well as sprite and collisionBox
	*	GetScale();
	* 
	*/
	class Actor : public Latno::Component
	{
		private:
			Coords position;
			void SetSpriteScale(float x, float y);
		public:
			glm::vec2 scale = { 1,1 };

			Sprite* sprite;
			CollisionBox* collisionBox;

			Coords preData;

			Coords direction = UP;
			float speed = 1.0f;
			

			Actor(float _x, float _y,std::string SpritePath);
			Actor(Coords _Pos, std::string SpritePath);
			Actor(float _x, float _y, glm::vec2 _scale, std::string SpritePath);

			Actor();

			bool CheckCollision(Actor Actor) const;
			bool CheckCollision(Coords Point) const;
			void SwapTexture(std::string path);

			Coords GetPos() const;
			void SetPos(Coords _pos);
			void SetCollisionSize(glm::vec2 scale);

			void SetScale(glm::vec2 _scale);
			glm::vec2 GetScale();


	};
}