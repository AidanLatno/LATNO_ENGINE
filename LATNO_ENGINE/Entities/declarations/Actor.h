#pragma once
#include "../../engine/declarations/Route.h"
#include "../../engine/declarations/Rendering/Renderer.h"


namespace Latno_Entities 
{
	class Actor : public Latno::Component
	{
		public:
			Sprite* sprite;
			Coords preData;
			Coords position;
			char ch;
			std::string name;
			Coords direction = UP; // "< " " >" "^^" "vv"
			

			Actor(int _x,int _y,char _ch,std::string SpritePath, std::string _Name = "");
			Actor(Coords _Pos,char _ch, std::string SpritePath, std::string _Name = "");
			Actor();

			void SetCoords(int x,int y);
			void SetCoords(Coords Pos);
			bool CheckCollision(Actor Actor) const;
			bool CheckCollision(Coords Point) const;
			bool IsNearby(Actor Actor) const;
			bool IsNearby(Coords Point) const;

	};
}