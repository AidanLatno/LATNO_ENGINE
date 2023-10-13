#pragma once
#include "../../Entities/declarations/Actor.h"

namespace Latno
{
	class Scene
	{
	private:
		Renderer renderer;
	public:
		GLFWwindow* window;
		int sizeY;
		int sizeX;
		int area;
		std::vector<Latno::Actor*> actors;
		std::vector<Latno::Actor> dynamicActors;

		Scene(int Width, int Length, GLFWwindow* _window);
		Scene(Coords Size, GLFWwindow* _window);

		~Scene();

		bool CheckBounds(Coords pos);
		void AddActor(Latno::Actor& Actor);
		void AddDynamicActor(Latno::Actor Actor);
		void DestroyActor(Latno::Actor* DeletedActor);
		void DestroyDynamicActor(int Index);
		void Render(bool DisplayChars = false, bool ClearScreen = true) const;
		bool ActorCollision(Latno::Actor Actor) const;
		bool ActorCollision(Coords Point) const;
		bool DynamicActorCollision(Latno::Actor Actor);
		bool DynamicActorCollision(Coords Point);
		void SetActorIndex(Latno::Actor& PassedActor, int Index);
		bool IsIn(Latno::Actor* Actor) const;
		Coords GetSize() const;
	};
}