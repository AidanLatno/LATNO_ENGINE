#pragma once
#include "../declarations/Scene.h"
#include <string>

namespace Latno
{
	Scene::Scene(int _width, int _length, GLFWwindow* _window)
	{
		window = _window;
		sizeX = _width;
		sizeY = _length;
		area = _length * _width;
	}

	Scene::Scene(Coords _size, GLFWwindow* _window)
	{
		window = _window;
		sizeX = _size.x;
		sizeY = _size.y;
		area = sizeY * sizeX;
	}

	Scene::~Scene()
	{
		//LOGLN("DESTROYED SCENE");
	}

	void Scene::AddActor(Latno::Actor& _actor)
	{
		actors.push_back(&_actor);
		renderer.AddSprite(_actor.sprite);
	}

	void Scene::AddDynamicActor(Latno::Actor _actor)
	{
		dynamicActors.push_back(_actor);
		renderer.AddSprite(_actor.sprite);
	}

	void Scene::DestroyActor(Latno::Actor* deletedActor)
	{
		std::vector<Latno::Actor*> tempArray;
		if (actors.size() > 0)
		{
			for (int i = 0; i < actors.size(); i++)
			{
				if (actors[i] != deletedActor)
					tempArray.push_back(actors[i]);
			}
			actors.swap(tempArray);
		}

		renderer.RemoveSprite(deletedActor->sprite);

	}

	void Scene::DestroyDynamicActor(int _index)
	{
		// dynamicactor.erase(dynamicactor[Index]);
		std::vector<Latno::Actor> tempArray;
		if (dynamicActors.size() > 0)
		{
			for (int i = 0; i < dynamicActors.size(); i++)
			{
				if (i != _index)
					tempArray.push_back(dynamicActors[i]);
			}
		}
		dynamicActors.swap(tempArray);
		// for(int i = 0; i < dynamicactor.size(); i++)
		// 	dynamicactor[i] = TempArray[i];

		renderer.RemoveSprite(actors.size() + _index);
	}

	void Scene::Render(bool _displayChars, bool _clearScreen) const
	{
		renderer.RenderSprites(window);
	}

	bool Scene::ActorCollision(Latno::Actor _actor) const
	{
		if (actors.size() > 0)
		{
			for (int i = 0; i < actors.size(); i++)
				if (actors[i]->collisionBox->CheckCollision(*_actor.collisionBox))
					return true;
		}
		return false;
	} // Returns true if there is something there

	bool Scene::ActorCollision(Coords _point) const
	{
		if (actors.size() > 0)
		{
			for (int i = 0; i < actors.size(); i++)
				if (actors[i]->GetPos().IsEqual(_point))
					return true;
		}
		return false;
	} // Returns true if there is something there

	bool Scene::DynamicActorCollision(Latno::Actor _actor)
	{
		if (dynamicActors.size() > 0)
		{
			for (int i = 0; i < dynamicActors.size(); i++)
				if (dynamicActors[i].collisionBox->CheckCollision(*_actor.collisionBox))
					return true;
		}
		return false;
	}

	bool Scene::DynamicActorCollision(Coords _point)
	{
		if (dynamicActors.size() > 0)
		{
			for (int i = 0; i < dynamicActors.size(); i++)
				if (dynamicActors[i].collisionBox->CheckCollision(_point))
					return true;
		}
		return false;
	}

	void Scene::SetActorIndex(Latno::Actor& _passedActor, int _index)
	{
		actors[_index] = &_passedActor;
	}

	bool Scene::CheckBounds(Coords pos)
	{
		if (pos.x < 0 || pos.y < 0 || pos.x >= sizeX || pos.y >= sizeY)
			return false;
		return true;
	}

	bool Scene::IsIn(Latno::Actor* _actor) const
	{
		if (actors.size() > 0)
		{
			for (int i = 0; i < actors.size(); i++)
			{
				if (actors[i] == _actor)
					return true;
			}
		}
		return false;
	}

	Coords Scene::GetSize() const
	{
		return { (float)sizeX,(float)sizeY };
	}
}