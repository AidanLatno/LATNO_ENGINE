// #pragma once

// #include "../declerations/Circle.h"

// Circle::Circle(Coords _Center,int _Radius,char _ch)
// {
//     Center = _Center;
// 	Radius = _Radius;
// 	ch = _ch;
// }

// bool Circle::CheckCollision(Coords Point)
// {
// 	int Leg1,Leg2;
//     float Hypotenuse;
	
// 	Leg1 = abs(Point.x - Center.x);
// 	Leg2 = abs(Point.y - Center.y);

// 	Hypotenuse = sqrt(pow(Leg1,2) + pow(Leg2,2));
// 	if(Hypotenuse < Radius - 0.5)
// 		return true;
// 	return false;
// }