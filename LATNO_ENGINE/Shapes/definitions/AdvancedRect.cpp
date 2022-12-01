#include "../declarations/AdvancedRect.h"


// Takes first coord as starting point and expands rect in a direction with following params
void AdvancedRect::RebuildRect(Coords _Direction, int _Distance, int _Width = 0)
{
	extendDirection = _Direction;
	distance = _Distance;
	width = _Width;

	Latno_Entities::AdvancedActor Tracer(corner1.x, corner1.y, '.', "RECT_TRACER");
	Coords EndPoint;
	Tracer.direction = extendDirection;
	Tracer.MoveFoward(distance);
	EndPoint = Tracer.position;

	if (extendDirection.IsEqual(RIGHT) || extendDirection.IsEqual(DOWN))
	{
		corner2 = EndPoint;
		if (extendDirection.IsEqual(RIGHT))
		{
			corner1.y -= width;
			corner2.y += width;
		}
		else
		{
			corner1.x -= width;
			corner2.x += width;
		}
	}
	else if (extendDirection.IsEqual(UP) || extendDirection.IsEqual(LEFT))
	{
		corner2 = corner1;
		corner1 = EndPoint;
		if (extendDirection.IsEqual(LEFT))
		{
			corner1.y -= width;
			corner2.y += width;
		}
		else
		{
			corner1.x -= width;
			corner2.x += width;
		}
	}
}
AdvancedRect AdvancedRect::R_RebuildRect(Coords _Direction, int _Distance, int _Width)
{
	extendDirection = _Direction;
	distance = _Distance;
	width = _Width;

	Latno_Entities::AdvancedActor Tracer(corner1.x, corner1.y, '.', "RECT_TRACER");
	Coords EndPoint;
	Tracer.direction = extendDirection;
	Tracer.MoveFoward(distance);
	EndPoint = Tracer.position;

	if (extendDirection.IsEqual(RIGHT) || extendDirection.IsEqual(DOWN))
	{
		corner2 = EndPoint;
		if (extendDirection.IsEqual(RIGHT))
		{
			corner1.y -= width;
			corner2.y += width;
		}
		else
		{
			corner1.x -= width;
			corner2.x += width;
		}
	}
	else if (extendDirection.IsEqual(UP) || extendDirection.IsEqual(LEFT))
	{
		corner2 = corner1;
		corner1 = EndPoint;
		if (extendDirection.IsEqual(LEFT))
		{
			corner1.y -= width;
			corner2.y += width;
		}
		else
		{
			corner1.x -= width;
			corner2.x += width;
		}
	}
	return *this;
}