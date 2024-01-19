#pragma once
#include <math.h>
#include "../../engine/declarations/Rendering/Renderer.h"
#include "ThreadManager.h"

namespace Latno
{
	/*
	* Class Name: Coords
	* Purpose: Acts as Latno Engine's "2d Vectors" or position. The name coords is short for coordinates.
	*		   Keeps track of position as well as vectors in 2d space.
	* Constructor: Initializes x and y
	* 
	* Methods:
	*	IsEqual(Coords a)
	*		- Compares 2 Coords to see if their values are the same. Pretty Obvious....
	*	Rotate(float Angle, float h, float k, float Rotations)
	*		- Rotates this point by the given angle, around the point (h,k). Repeats this process for the amount provided by the Rotations parameter.
	*		- Default angle is 90, default point for (h,k) is (0,0) and rotations is set to 1.
	*	FindDistance(coords a)
	*		- Gets the distance between this and the given parameter.
	*	dSin(float theta)
	*		- find the sin of theta in degrees.
	*	dCos(float theta)
	*		- find the cosine of theta in degrees.
	*/
	struct Coords
	{
		float x;
		float y;

		Coords();
		Coords(float _x, float _y);

		Coords(int _x, int _y);

		Coords(double _x, double _y);

		Coords operator + (Coords obj);
		Coords operator - (Coords obj);
		Coords operator * (Coords obj);
		Coords operator / (Coords obj);
		
		bool operator != (Coords obj);
        bool operator == (Coords obj);
		Coords operator = (Coords obj);
		Coords operator += (Coords obj);
		Coords operator -= (Coords obj);
		Coords operator *= (Coords obj);
		Coords operator /= (Coords obj);

		Coords operator * (float obj);
		Coords operator / (float obj);
		Coords operator + (float obj);
		Coords operator - (float obj);

		bool operator != (float obj);
        bool operator == (float obj);
		Coords operator = (float obj);
		Coords operator *= (float obj);
		Coords operator /= (float obj);
		Coords operator += (float obj);
		Coords operator -= (float obj);

		Coords operator * (glm::vec2 obj);
		Coords operator / (glm::vec2 obj);
		Coords operator + (glm::vec2 obj);
		Coords operator - (glm::vec2 obj);

		bool operator != (glm::vec2 obj);
		bool operator == (glm::vec2 obj);
		Coords operator = (glm::vec2 obj);
		Coords operator *= (glm::vec2 obj);
		Coords operator /= (glm::vec2 obj);
		Coords operator += (glm::vec2 obj);
		Coords operator -= (glm::vec2 obj);

		bool IsEqual(Coords a) const;
		void Rotate(float Angle, float h, float k, float Rotations);
		double FindDistance(Coords a);


		float dSin(float theta);

		float dCos(float theta);
	};
}