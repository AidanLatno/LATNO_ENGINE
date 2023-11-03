#include "../../Entities/declarations/AdvancedActor.h"

namespace Latno
{
	void AdvancedActor::MoveForward(Scene &_scene)
	{
		preData = GetPos();
		SetPos(GetPos() + (direction * (speed * GLOBAL_DELTA_TIME)));

		if(GetPos().x >= _scene.sizeX || GetPos().y >= _scene.sizeY || GetPos().x < 0 || GetPos().y < 0)
		{
			SetPos(preData);
			return;
		}
	}

	void AdvancedActor::MoveForward()
	{
		preData = GetPos();
		SetPos(GetPos() + direction * (speed * GLOBAL_DELTA_TIME));
	}

	void AdvancedActor::MoveForward(int _sizeX, int _sizeY)
	{
		preData = GetPos();
		SetPos(GetPos() + direction * (speed * GLOBAL_DELTA_TIME));

		if(GetPos().x >= _sizeX || GetPos().y >= _sizeY || GetPos().x < 0 || GetPos().y < 0)
		{
			SetPos(preData);
			return;
		}
	}

	void AdvancedActor::TurnRight(float deg)
	{
		Coords temp = direction;
		direction.x = temp.x * Coords().dCos(-deg) - temp.y * Coords().dSin(-deg);
		direction.y = temp.x * Coords().dSin(-deg) + temp.y * Coords().dCos(-deg);
		
	}

	void AdvancedActor::TurnLeft(float deg)
	{
		Coords temp = direction;
		
		direction.x = temp.x * Coords().dCos(deg) - temp.y * Coords().dSin(deg);
		direction.y = temp.x * Coords().dSin(deg) + temp.y * Coords().dCos(deg);
		
	}
}