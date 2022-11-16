#include "../../Entities/declarations/AdvancedActor.h"


void Latno_Entities::AdvancedActor::SendBack()
{
	position = preData;
}

void Latno_Entities::AdvancedActor::MoveFoward(Scene &_scene, int _speed)
{
	for(int i = 0; i < _speed; i++)
	{
		preData = position;
		position += direction;

		if(position.x >= _scene.sizeX || position.y >= _scene.sizeY || position.x < 0 || position.y < 0)
		{
			position = preData;
			return;
		}
	}
}

void Latno_Entities::AdvancedActor::MoveFoward(int _speed)
{
	preData = position;
	position += direction * _speed;
}

void Latno_Entities::AdvancedActor::MoveFoward(int _sizeX, int _sizeY, int _speed)
{
	for(int i = 0; i < _speed; i++)
	{
		preData = position;
		position += direction;

		if(position.x >= _sizeX || position.y >= _sizeY || position.x < 0 || position.y < 0)
		{
			position = preData;
			return;
		}
	}
}

void Latno_Entities::AdvancedActor::TurnRight(int _turnAmount = 1)
{
	Coords temp = direction;
	for(int i = 0; i < _turnAmount; i++)
	{
		direction.x = temp.x * Coords().dCos(-90) - temp.y * Coords().dSin(-90);
		direction.y = temp.x * Coords().dSin(-90) + temp.y * Coords().dCos(-90);
	}
}

void Latno_Entities::AdvancedActor::TurnLeft(int _turnAmount = 1)
{
	Coords temp = direction;
	for(int i = 0; i < _turnAmount; i++)
	{
		direction.x = temp.x * Coords().dCos(90) - temp.y * Coords().dSin(90);
		direction.y = temp.x * Coords().dSin(90) + temp.y * Coords().dCos(90);
	}
}

void Latno_Entities::AdvancedActor::TurnRandom(bool up, bool right, bool down, bool left)
{
	Coords directions[4];
	int i = 0;
	if(up)
	{
		directions[i] = UP;
		i++;
	}
	if(right)
	{
		directions[i] = RIGHT;
		i++;
	}
	if(down)
	{
		directions[i] = DOWN;
		i++;
	}
	if(left)
	{
		directions[i] = LEFT;
		i++;
	}
	direction = directions[rand() % i];
}

bool Latno_Entities::AdvancedActor::IsNearby(Actor _actor, int _size) const
{
	Rect AreaScanner(position.x - _size, position.y - _size, position.x + _size, position.y + _size, '.', "AREASCANNER");
	return AreaScanner.CheckCollision(_actor);
}

int Latno_Entities::AdvancedActor::CountNearby(Scene _scene, int _size = 1)
{
	int amount = 0;
	// Rect AreaScanner(position.x - Size,position.y - Size,position.x + Size,position.y + Size,'.',"AREASCANNER");
	// for(int i = 0; i < Scene.ActorAmount; i++)
	// 	if(AreaScanner.CheckCollision(Scene.Actors[i]->position))
	// 		Amount++;
	// for(int i = 0; i < Scene.DynamicActors.size(); i++)
	// 	if(AreaScanner.CheckCollision(Scene.DynamicActors[i].position))
	// 		Amount++;
	return amount;
}