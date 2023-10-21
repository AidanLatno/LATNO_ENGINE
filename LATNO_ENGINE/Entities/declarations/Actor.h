#pragma once
#include "../../engine/declarations/Rendering/Renderer.h"
#include "../../engine/declarations/CollisionBox.h"


namespace Latno
{
	/*
	* Class Name: Actor
	* Purpose: An actor is a object that exists within the game, or scene. Can be anything from a tree in the background to the player.
	* Parents: Component -> Behavior
	* 
	* Constructors:
	*	Actor(float _x, float _y, string SpritePath)
	*		- Sets the position, creates a sprite using SpritePath and initializes a collisionBox.
	*	Actor(Coords _Pos, std::string SpritePath)
	*		- Sets the position, creates a sprite using SpritePath and initializes a collisionBox.
	*	Actor(float _x, float _y, glm::vec2 _scale, std::string SpritePath);
	*		- Sets the position, scale, creates a sprite using SpritePath and initializes a collisionBox.
	*	Actor()
	*		- Sets position to 0,0 and creates a collision box with a 50x50 size
	* 
	* Variables:
	*	position
	*		- Contains the current coordinates of the Actor
	*	sprite
	*		- Contains the sprite the actor sends to the renderer
	*	collisionBox
	*		- object used for detecting collision with other actors
	*		- Default size is 50x50
	*	scale
	*		- x and y scale for the actor's sprite and collisionBox
	*	preData
	*		- Contains the actor's last position before they moved.
	*	direction
	*		- Can be used as a directional vector for movement
	*		- Default is "UP" aka Coords(0,1)
	*	speed
	*		- Determines how fast the object should move if needed.
	*	
	* 
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
	*		- private
	*		- sets the scale for the sprite
	*	SetCollisionSize(glm::vec2 scale);
	*		- Sets the size of the collisionBox
	*	SetScale(glm::vec2 _scale);
	*		- sets the scale of this actor
	*	GetScale()
	*		- returns the scale of this actor
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