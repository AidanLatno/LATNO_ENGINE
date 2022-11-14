#pragma once
#include "../../Shapes/declarations/Circle.h"

class Scene
{
	private:
		std::string Convert(Coords Direction) const;
	public:
		bool devMode = false;
		char devModeColor;
		char fillColor;
		int sizeY;
		int sizeX;
		int area;
		std::vector<Latno_Entities::Actor*> actors;
		std::vector<Latno_Entities::Actor> dynamicActors;
		std::vector<Rect*> rects;
		char** grid;

		Scene(int Width,int Length);
		Scene(Coords Size);

		~Scene();

		void AddActor(Latno_Entities::Actor &Actor);
		void AddDynamicActor(Latno_Entities::Actor Actor);
		void DestroyActor(Latno_Entities::Actor *DeletedActor);
		void DestroyDynamicActor(int Index);
		void AddRect(Rect &Rect);
		void Update();
		void Render(bool DisplayChars = false,bool ClearScreen = true) const;
		bool ActorCollision(Latno_Entities::Actor Actor) const;
		bool ActorCollision(Coords Point) const;
		bool DynamicActorCollision(Latno_Entities::Actor Actor);
		bool DynamicActorCollision(Coords Point);
		bool RectCollision(Coords Point) const;
		void SetActorIndex(Latno_Entities::Actor &PassedActor,int Index);
		void SetRectIndex(Rect &PassedRect,int Index);
		bool RectCollision(Latno_Entities::Actor const Actor) const;
		bool IsIn(Latno_Entities::Actor *Actor) const;
		Coords GetSize() const;
};