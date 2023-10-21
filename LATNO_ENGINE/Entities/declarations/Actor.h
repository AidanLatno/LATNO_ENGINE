#pragma once
#include "../../engine/declarations/Rendering/Renderer.h"
#include "../../Shapes/declarations/CollisionBox.h"


namespace Latno
{
	/*
	* Class Name: Actor
	* Parents: Component -> Behavior
	* 
	* Constructors:
	* 
	* Variables:
	* 
	* Methods:
	*	CheckCollision(Actor Actor)
	*		- Returns true if parameter actor is colliding with this
	*	CheckCollision(Coords Point)
	*		- Returns true if parameter actor is within this
	*	SwapTexture(string path)
	*		- Changes the texture of the actor to the file specified
	*
	*	GetPos()
	*		- Returns the position value
	*	SetPos(Coords _pos)
	*		- Sets the position value to parameter
	*	SetSpriteScale(float x, float y)
	*		
	*	SetCollisionSize(glm::vec2 scale);
	*
	*	SetScale(glm::vec2 _scale);
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