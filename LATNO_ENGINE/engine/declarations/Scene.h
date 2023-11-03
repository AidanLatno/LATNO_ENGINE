#pragma once
#include "../../Entities/declarations/Actor.h"

namespace Latno
{
	/*
	* Class Name: Scene
	* Purpose: The scene is the world your game is in. It contains all actors and will take their textures to render them.
	*		   You can have multiple scenes and switch between them using the mainscene pointer in the application.
	* 
	* Constructors:
	*	Scene(int Width, int Length, GLFWwindow* _window);
	*	Scene(Coords Size, GLFWwindow* _window);
	*
	*	~Scene();
	* 
	* Variables
	*	Renderer renderer;
	*		- private instance of the Renderer class
	*		- Used to render the actor's sprites
	*	GLFWwindow* window;
	*		- Reference to the window the program is rendering to
	*	int sizeY;
	*		- Vertical length
	*	int sizeX;
	*		- Horizontal length
	*	int area;
	*		- total pixel area of scene (sizeX*sizeY)
	*	vector<Actor*> actors;
	*		- List of pointers to actors that have been added to the scene.
	*		- Used for individual objects such as a player or a wall.
	*	vector<Actor> dynamicActors;
	*		- List of actors that have been added. (Creates a copy of added actors)
	*		- Used for mass objects such as projectiles, enemies that spawn in large numbers and get killed, etc.
	*	
	* Methods:
	*	CheckBounds(pos)
	*		- Returns true if the point is within the bounds of the scene
	*	AddActor(Actor actor)
	*		- Adds a actor to the scene
	*	AddDynamicActor(Actor actor)
	*		- Adds a dynamic actor to the scene
	*	DestroyActor(Actor DeletedActor)
	*		- Removes an actor from the scene
	*	DestroyDynamicActor(int index)
	*		- Removes the dynamic actor at index and shifts the array to fill the empty space
	*	Render()
	*		- Renders the current frame of the scene to the screen
	*	ActorCollision(Actor Actor)
	*		- Detects if any of the actors within the scene are colliding with this actor
	*	ActorCollision(Coords Point)
	*		- Detects if any of the actors within the scene are colliding with this point
	*	DynamicActorCollision(Actor Actor)
	*		- Detects if any of the dynamic actors within the scene are colliding with this actor
	*	DynamicActorCollision(Coords Point)
	*		- Detects if any of the dynamic actors within the scene are colliding with this point
	*	SetActorIndex(Actor& PassedActor, int Index)
	*		- Changes the actor in a specific index to the passed in actor
	*	IsIn(Actor* Actor)
	*		- Returns true if the passed actor is within the scene
	*	GetSize()
	*		- Returns a coords of the size of the scene
	*	
	*/
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
		void Render() const;
		bool ActorCollision(Latno::Actor Actor) const;
		bool ActorCollision(Coords Point) const;
		bool DynamicActorCollision(Latno::Actor Actor);
		bool DynamicActorCollision(Coords Point);
		void SetActorIndex(Latno::Actor& PassedActor, int Index);
		bool IsIn(Latno::Actor* Actor) const;
		Coords GetSize() const;
	};
}