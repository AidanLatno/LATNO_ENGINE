#pragma once
#include "../../Entities/declarations/AdvancedActor.h"

class AdvancedRect : public Rect
{
using Rect::Rect;
public:
	Coords extendDirection;
	int distance;
	int width;

	// Takes first coord as starting point and expands rect in a direction with following params
	void RebuildRect(Coords _Direction, int _Distance, int _Width);
	AdvancedRect R_RebuildRect(Coords _Direction, int _Distance, int _Width = 0);
};