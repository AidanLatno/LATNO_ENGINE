#pragma once

#include "../../Entities/declarations/Patroller.h"

namespace Latno_Animation 
{
	class Frame
	{
		public:
			Scene *inheritedScene;
			bool devMode = false;
			char devModeColor = ToChar("void");
			char fillColor = ToChar("white");
			int sizeX,sizeY;
			
			std::vector<Rect> rects;
			std::vector<Circle> circles;
			std::vector<Triangle> triangles;

			char** grid;

			Frame(int _sizeX,int _SizeY);
			Frame(Scene Scene);

			void Reset();

			// (Coords TipPos,std::string Direction,int Length,int Width,char Color)
			void AddTriangle(Coords TipPos,Coords Direction,int Length,int Width,char Color);

			void AddTriangle(Triangle T);

			void ResetTriangles();
			// (Coords Pos1,Coords Pos2,char ch)
			void AddRect(Coords Pos1,Coords Pos2,char ch);
			void AddRect(Rect R);
			void ResetRects();
			void AddCircle(Coords Center, int Radius, char Color);
						
			void AddCircle(Circle C);
		
			void ResetCircles();
			void InheritFrame(Frame Frame);

			
			void Update(bool UseInheritedScene = false);
			void Render();
	};	
}