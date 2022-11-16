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

Scene::Scene(int _width, int _length)
{
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

Scene::Scene(Coords _size)
{
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
}

void Scene::AddDynamicActor(Latno_Entities::Actor _actor)
{
	dynamicActors.push_back(_actor);
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
}

void Scene::AddRect(Rect &_rect)
{
	rects.push_back(&_rect);
}

void Scene::Update()
{
	if(!devMode)
		{
			for (int y = 0; y < sizeY; ++y)
				for (int x = 0; x < sizeX; ++x)
					grid[y][x] = fillColor;
		}
		else
		{
			bool even = true;
			for (int y = 0; y < sizeY; ++y)
			{
				for (int x = 0; x < sizeX; ++x)
				{
					even = !even;
					if(even)
						grid[y][x] = fillColor;
					else
						grid[y][x] = devModeColor;
				}
				if(sizeX % 2 == 0 && sizeY % 2 == 0)
					even = !even;
			}
		}

	if(actors.size() > 0)
		for(int i = 0; i < dynamicActors.size(); i++)
			grid[dynamicActors[i].position.y][dynamicActors[i].position.x] = dynamicActors[i].ch;

	if(actors.size() > 0)
		for (int i = 0; i < actors.size(); i++)
			grid[actors[i]->position.y][actors[i]->position.x] = actors[i]->ch;

	if(rects.size() > 0)
		for(int y = 0; y < sizeX; y++)
			for(int x = 0; x < sizeY; x++)
				for(int i = 0; i < rects.size(); i++)
					if(x >= rects[i]->corner1.x && x <= rects[i]->corner2.x && y >= rects[i]->corner1.y && y <= rects[i]->corner2.y)
						grid[y][x] = rects[i]->ch;
}

void Scene::Render(bool _displayChars, bool _clearScreen) const
{
	if (_clearScreen)
		CLEAR_SCREEN;
	std::string str;
	
	for(int y = 0; y < sizeY; y++)
	{
		for(int x = 0; x < sizeX; x++)
		{
			if(!_displayChars)
			{
				if(grid[y][x] == 'p')
					str = "\033[44m";
				else if(grid[y][x] == '.')
					str = "\033[47m";
				else if(grid[y][x] == 'e')
					str = "\033[41m";
				else if(grid[y][x] == '#')
					str = "\033[45m";
				else if(grid[y][x] == 'a')
					str = "\033[43m";
				else if(grid[y][x] == 'g')
					str = "\033[42m";
				else if(grid[y][x] == 'b')
					str = "\033[46m";
				else
					str = "\033[0m";
				
				if (actors.size() > 0)
				{
					for (int i = 0; i < actors.size(); i++)
					{
						if (y == actors[i]->position.y && x == actors[i]->position.x)
						{
							std::cout << str << Convert(actors[i]->direction) << "\033[0m";
							break;
						}
						else if (i == actors.size() - 1)
						{
							std::cout << str + "  \033[0m";
							break;
						}
					}
				}
			}
			else
				std::cout << grid[y][x] << ' ';
		}
		std::cout << '\n';
	}
}

bool Scene::ActorCollision(Latno_Entities::Actor _actor) const
{
	if (actors.size() > 0)
	{
		for (int i = 0; i < actors.size(); i++)
			if (actors[i]->position.IsEqual(_actor.position) && actors[i]->name != _actor.name)
				return true;
	}
	return false;
} // Returns true if there is something there

bool Scene::ActorCollision(Coords _point) const
{
	if (actors.size() > 0)
	{
		for (int i = 0; i < actors.size(); i++)
			if (actors[i]->position.IsEqual(_point))
				return true;
	}
	return false;
} // Returns true if there is something there

bool Scene::DynamicActorCollision(Latno_Entities::Actor _actor)
{
	if (dynamicActors.size() > 0)
	{
		for (int i = 0; i < dynamicActors.size(); i++)
			if (dynamicActors[i].position.IsEqual(_actor.position) && dynamicActors[i].name != _actor.name)
				return true;
	}
	return false;
}

bool Scene::DynamicActorCollision(Coords _point)
{
	if (dynamicActors.size() > 0)
	{
		for (int i = 0; i < dynamicActors.size(); i++)
			if (dynamicActors[i].position.IsEqual(_point))
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

void Scene::SetRectIndex(Rect &_passedRect, int _index)
{
	rects[_index] = &_passedRect;
}

bool Scene::RectCollision(Latno_Entities::Actor const Actor) const
{
	if (rects.size() > 0)
	{
		for (int i = 0; i < rects.size(); i++)
		{
			if (!(Actor.position.x >= rects[i]->corner1.x && Actor.position.x <= rects[i]->corner2.x))
				continue;

			if (Actor.position.y >= rects[i]->corner2.y && Actor.position.y <= rects[i]->corner2.y)
				return true;
		}
	}
	return false;
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
