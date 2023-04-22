#pragma once
#include "../declarations/Scene.h"
#include <string>
    
std::string Scene::Convert(Coords _direction) const
{
	if(_direction.IsEqual(UP))
		return "^^";
	else if(_direction.IsEqual(RIGHT))
		return " >";
	else if(_direction.IsEqual(DOWN))
		return "vv";
	else if(_direction.IsEqual(LEFT))
		return "< ";
	return "xx";
}

Scene::Scene(int _width, int _length, GLFWwindow* _window)
{
	window = _window;
	devModeColor = ToChar("void");
	fillColor = ToChar("white");
	sizeX = _width;
	sizeY = _length;
	area = _length * _width;
	grid = new char*[sizeY];

	for(int i = 0; i < sizeY; ++i)
		grid[i] = new char[sizeX];
	
	for (int y = 0; y < sizeY; ++y)
		for (int x = 0; x < sizeX; ++x)
			grid[y][x] = fillColor;
}

Scene::Scene(Coords _size, GLFWwindow* _window)
{
	window = _window;
	sizeX = _size.x;
	sizeY = _size.y;
	area = sizeY * sizeX;
	grid = new char*[sizeY];

	for(int i = 0; i < sizeY; ++i)
		grid[i] = new char[sizeX];
	
	for (int y = 0; y < sizeY; ++y)
		for (int x = 0; x < sizeX; ++x)
			grid[y][x] = fillColor;


	//LOGLN("Scene with size: (" + std::to_string(sizeX) + ", " + std::to_string(sizeY) + ") was successfully created");
}

Scene::~Scene()
{
	for(int i = 0; i < sizeY; ++i)
		delete[] grid[i];
	delete[] grid;
	//LOGLN("DESTROYED SCENE");
}

void Scene::AddActor(Latno_Entities::Actor &_actor)
{
	actors.push_back(&_actor);
	renderer.AddSprite(_actor.sprite);
}

void Scene::AddDynamicActor(Latno_Entities::Actor _actor)
{
	dynamicActors.push_back(_actor);
	renderer.AddSprite(_actor.sprite);
}

void Scene::DestroyActor(Latno_Entities::Actor *deletedActor)
{
	std::vector<Latno_Entities::Actor*> tempArray;
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
	std::vector<Latno_Entities::Actor> tempArray;
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

	renderer.RemoveSprite(_index);
}

void Scene::AddRect(CollisionBox &_rect)
{
	rects.push_back(&_rect);
}

void Scene::Render(bool _displayChars, bool _clearScreen) const
{
	renderer.RenderSprites(window);
}



bool Scene::ActorCollision(Latno_Entities::Actor _actor) const
{
	if (actors.size() > 0)
	{
		for (int i = 0; i < actors.size(); i++)
			if (actors[i]->GetPos().IsEqual(_actor.GetPos()) && actors[i]->name != _actor.name)
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

bool Scene::DynamicActorCollision(Latno_Entities::Actor _actor)
{
	if (dynamicActors.size() > 0)
	{
		for (int i = 0; i < dynamicActors.size(); i++)
			if (dynamicActors[i].GetPos().IsEqual(_actor.GetPos()) && dynamicActors[i].name != _actor.name)
				return true;
	}
	return false;
}

bool Scene::DynamicActorCollision(Coords _point)
{
	if (dynamicActors.size() > 0)
	{
		for (int i = 0; i < dynamicActors.size(); i++)
			if (dynamicActors[i].GetPos().IsEqual(_point))
				return true;
	}
	return false;
}

bool Scene::RectCollision(Coords _point) const
{
	if (rects.size() > 0)
	{
		for (int i = 0; i < rects.size(); i++)
		{
			if (!(_point.x >= rects[i]->corner1.x && _point.x <= rects[i]->corner2.x))
				continue;

			if (_point.y >= rects[i]->corner1.y && _point.y <= rects[i]->corner2.y)
				return true;
		}
	}
	return false;
}

void Scene::SetActorIndex(Latno_Entities::Actor &_passedActor,int _index)
{
	actors[_index] = &_passedActor;
}

void Scene::SetRectIndex(CollisionBox &_passedRect, int _index)
{
	rects[_index] = &_passedRect;
}

bool Scene::RectCollision(Latno_Entities::Actor const Actor) const
{
	if (rects.size() > 0)
	{
		for (int i = 0; i < rects.size(); i++)
		{
			if (!(Actor.GetPos().x >= rects[i]->corner1.x && Actor.GetPos().x <= rects[i]->corner2.x))
				continue;

			if (Actor.GetPos().y >= rects[i]->corner2.y && Actor.GetPos().y <= rects[i]->corner2.y)
				return true;
		}
	}
	return false;
}

bool Scene::CheckBounds(Coords pos)
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= sizeX || pos.y >= sizeY)
		return false;
	return true;
}

bool Scene::IsIn(Latno_Entities::Actor *_actor) const
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
	return {sizeX,sizeY};
}
