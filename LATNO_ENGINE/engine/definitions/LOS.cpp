#include "../declarations/LOS.h"


float LOS::sign(Coords p1, Coords p2, Coords p3) const
{
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

LOS::LOS(Coords _StartPos, Coords _Direction, int _Distance, int _OutDistance)
{
	StartPos = _StartPos;
	Direction = _Direction;
	Distance = _Distance;
	OutDistance = _OutDistance;

	this->RecalcPoints();
}

void LOS::RecalcPoints()
{
	Points[0] = StartPos;
	if(Direction.IsEqual(UP))
	{
		Points[1] = {StartPos.x - OutDistance,StartPos.y - Distance};
		Points[2] = {StartPos.x + OutDistance,StartPos.y - Distance};
	}
	else if(Direction.IsEqual(DOWN))
	{
		Points[1] = {StartPos.x - OutDistance,StartPos.y + Distance};
		Points[2] = {StartPos.x + OutDistance,StartPos.y + Distance};
	}
	else if(Direction.IsEqual(RIGHT))
	{
		Points[1] = {StartPos.x + Distance,StartPos.y - OutDistance};
		Points[2] = {StartPos.x + Distance,StartPos.y + OutDistance};
	}
	else if(Direction.IsEqual(LEFT))
	{
		Points[1] = {StartPos.x - Distance,StartPos.y - OutDistance};
		Points[2] = {StartPos.x - Distance,StartPos.y + OutDistance};
	}
}
	
bool LOS::CheckCollision(Coords pt) const
{
	float d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(pt, Points[0], Points[1]);
	d2 = sign(pt, Points[1], Points[2]);
	d3 = sign(pt, Points[2], Points[0]);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
	
bool LOS::CheckCollision(Latno_Entities::Actor actor) const
{
	float d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(actor.position, Points[0], Points[1]);
	d2 = sign(actor.position, Points[1], Points[2]);
	d3 = sign(actor.position, Points[2], Points[0]);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}