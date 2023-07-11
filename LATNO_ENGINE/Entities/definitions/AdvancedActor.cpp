#include "../../Entities/declarations/AdvancedActor.h"

namespace Latno
{
	void AdvancedActor::SendBack()
	{
		SetPos(preData);
	}

	void AdvancedActor::MoveForward(Scene &_scene, float deltaTime)
	{
		preData = GetPos();
		SetPos(GetPos() + (direction * (speed * deltaTime)));

		if(GetPos().x >= _scene.sizeX || GetPos().y >= _scene.sizeY || GetPos().x < 0 || GetPos().y < 0)
		{
			SetPos(preData);
			return;
		}
	}

	void AdvancedActor::MoveForward(int _speed)
	{
		preData = GetPos();
		SetPos(GetPos() + direction * speed);
	}

	void AdvancedActor::MoveForward(int _sizeX, int _sizeY, int _speed)
	{
		preData = GetPos();
		SetPos(GetPos() + direction * speed);

		if(GetPos().x >= _sizeX || GetPos().y >= _sizeY || GetPos().x < 0 || GetPos().y < 0)
		{
			SetPos(preData);
			return;
		}
	}

	void AdvancedActor::TurnRight(int _turnAmount = 1)
	{
		Coords temp = direction;
		for(int i = 0; i < _turnAmount; i++)
		{
			direction.x = temp.x * Coords().dCos(-90) - temp.y * Coords().dSin(-90);
			direction.y = temp.x * Coords().dSin(-90) + temp.y * Coords().dCos(-90);
		}
	}

	void AdvancedActor::TurnLeft(int _turnAmount = 1)
	{
		Coords temp = direction;
		for(int i = 0; i < _turnAmount; i++)
		{
			direction.x = temp.x * Coords().dCos(90) - temp.y * Coords().dSin(90);
			direction.y = temp.x * Coords().dSin(90) + temp.y * Coords().dCos(90);
		}
	}

	void AdvancedActor::TurnRandom(bool up, bool right, bool down, bool left)
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

	int AdvancedActor::CountNearby(Scene _scene, int _size = 1)
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
}