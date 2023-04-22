#pragma once
#include "../../engine/declarations/Rendering/Renderer.h"
#include "../../Shapes/declarations/CollisionBox.h"


namespace Latno_Entities 
{
	class Actor : public Latno::Component
	{
		private:
			Coords position;
			glm::vec2 scale;
		public:
			Sprite* sprite;
			CollisionBox* collisionBox;

			Coords preData;
			
			std::string name;
			Coords direction = UP; // "< " " >" "^^" "vv"
			float speed = 1.0f;
			

			Actor(int _x,int _y,std::string SpritePath, std::string _Name = "");
			Actor(Coords _Pos, std::string SpritePath, std::string _Name = "");
			Actor(Coords _Pos, std::string SpritePath, std::string _name, std::string SpritePath, std::string _name = "");

			Actor();

			void SetCoords(int x,int y);
			void SetCoords(Coords Pos);
			bool CheckCollision(Actor Actor) const;
			bool CheckCollision(Coords Point) const;
			bool IsNearby(Actor Actor) const;
			bool IsNearby(Coords Point) const;

			Coords GetPos() const;
			void SetPos(Coords _pos);
			void SetScale(float x, float y);

			void SetScale(glm::vec2 _scale);
			glm::vec2 GetScale();


	};
}