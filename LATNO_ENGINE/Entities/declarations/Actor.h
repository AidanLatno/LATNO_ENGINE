#pragma once
#include "../../engine/declarations/Route.h"

namespace Latno_Entities 
{
	class Actor : public Latno::Component
	{
		public:
			Coords preData;
			Coords position;
			char ch;
			std::string name;
			Coords direction = UP; // "< " " >" "^^" "vv"
			std::vector<std::string> TagVector;

			Actor(int _x,int _y,char _ch,std::string _Name);
			Actor(Coords _Pos,char _ch,std::string _Name);
			Actor();

			void SetCoords(int x,int y);
			void SetCoords(Coords Pos);
			void AddTag(std::string TagToAdd);
			void RemoveTag(std::string TagToRemove);
			bool IfHasTag(std::string Tag);
			bool CheckCollision(Actor Actor) const;
			bool CheckCollision(Coords Point) const;
			bool IsNearby(Actor Actor) const;
			bool IsNearby(Coords Point) const;

	};
}