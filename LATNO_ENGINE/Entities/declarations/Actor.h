#pragma once
#include "../../engine/declarations/Rendering/Renderer.h"
#include "../../Shapes/declarations/CollisionBox.h"


namespace Latno
{
	class Actor : public Latno::Component
	{
		private:
			Coords position;
		public:
			glm::vec2 scale = { 1,1 };

			Sprite* sprite;
			CollisionBox* collisionBox;

			Coords preData;

			glm::vec2 size;
            unsigned int Radius;



			std::string name;
			Coords direction = UP; // "< " " >" "^^" "vv"
			float speed = 1.0f;
			

			Actor(int _x,int _y,std::string SpritePath, std::string _Name = "");
			Actor(Coords _Pos, std::string SpritePath, std::string _Name = "");
			Actor(int _x, int _y, glm::vec2 _scale, std::string SpritePath, std::string _name);

			Actor();

			void SetCoords(int x,int y);
			void SetCoords(Coords Pos);
			bool CheckCollision(Actor Actor) const;
			bool CheckCollision(Coords Point) const;
			bool IsNearby(Actor Actor) const;
			bool IsNearby(Coords Point) const;
			void SwapTexture(std::string path);

			Coords GetPos() const;
			void SetPos(Coords _pos);
			void SetSpriteScale(float x, float y);
			void SetCollisionSize(glm::vec2 scale);

			void SetScale(glm::vec2 _scale);
			glm::vec2 GetScale();


	};
}