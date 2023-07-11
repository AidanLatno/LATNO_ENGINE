#pragma once

#include "../../Shapes/declarations/Circle.h"
namespace Latno
{
    Circle::Circle(Coords _center, int _radius, char _ch)
    {
        center = _center;
        radius = _radius;
        ch = _ch;
    }

    bool Circle::CheckCollision(Coords point)
    {
        int leg1, leg2;
        float hypotenuse;

        leg1 = abs(point.x - center.x);
        leg2 = abs(point.y - center.y);

        hypotenuse = sqrt(pow(leg1, 2) + pow(leg2, 2));
        if (hypotenuse < radius - 0.5)
            return true;
        return false;
    }
}