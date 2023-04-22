#pragma once
#include "../../engine/declarations/Route.h"
#include "../../engine/declarations/Rendering/Renderer.h"


namespace Latno_Entities 
{
	class Actor : public Latno::Component
	{
		private:
			Coords position;
		public:
			Sprite* sprite;
			Coords preData;
			
			std::string name;
			Coords direction = UP; // "< " " >" "^^" "vv"
			float speed = 1.0f;
			

			Actor(int _x,int _y,std::string SpritePath, std::string _Name = "");
			Actor(Coords _Pos, std::string SpritePath, std::string _Name = "");
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

	};
}