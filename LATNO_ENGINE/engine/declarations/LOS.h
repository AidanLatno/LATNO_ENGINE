#pragma once
#include "../../Entities/declarations/AdvancedActor.h"

class LOS
{
private:
	float sign (Coords p1, Coords p2, Coords p3) const;
public:
	Coords StartPos;
	Coords Direction;
	int Distance;
	int OutDistance;
	Coords Points[3];

	LOS(Coords _StartPos, Coords _Direction, int _Distance, int _OutDistance);

	void RecalcPoints();

	bool CheckCollision(Coords pt) const;
	bool CheckCollision(Latno_Entities::Actor Actor) const;
};