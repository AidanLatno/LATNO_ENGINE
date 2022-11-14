#pragma once
#include "../declarations/Frame.h"

namespace Latno_Animation 
{    
    Frame::Frame(int _sizeX, int _sizeY) {
		sizeX = _sizeX;
    	sizeY = _sizeY;
		grid = new char*[sizeY];
			
		for(int i = 0; i < sizeY; ++i)
	    	grid[i] = new char[sizeX];
						
		for (int y = 0; y < sizeY; ++y)
			for (int x = 0; x < sizeX; ++x)
			    grid[y][x] = '.';
	}

    Frame::Frame(Scene Scene)
	{
    	grid = Scene.grid;
	}

    void Frame::Reset()
	{
		ResetCircles();
		ResetRects();
	    ResetTriangles();
		fillColor = ToChar("white");
	}

    void Frame::AddTriangle(Coords TipPos,Coords Direction,int Length,int Width,char Color)
	{
        Triangle TempT(TipPos,Direction,Length,Width);
		TempT.ch = Color;
	    triangles.push_back(TempT);
	}

    void Frame::AddTriangle(Triangle T)
	{
		triangles.push_back(T);
	}

    void Frame::ResetTriangles()
	{
	    triangles.clear();
	}

    
	void Frame::AddRect(Coords Pos1,Coords Pos2,char ch)
	{
		rects.push_back(Rect(Pos1.x,Pos1.y,Pos2.x,Pos2.y,ch,"FRAME_RECT"));
	}
	void Frame::AddRect(Rect R)
	{
		rects.push_back(R);
	}
	void Frame::ResetRects()
	{
		rects.clear();
	}
	void Frame::AddCircle(Coords Center, int Radius, char Color)
	{
		circles.push_back(Circle(Center,Radius,Color));
	}
	void Frame::AddCircle(Circle C)
	{
		circles.push_back(C);
	}
	void Frame::ResetCircles()
	{
		circles.clear();
	}
	void Frame::InheritFrame(Frame Frame)
	{
		rects = Frame.rects;
		circles = Frame.circles;
		triangles = Frame.triangles;
		inheritedScene = Frame.inheritedScene;
		fillColor = Frame.fillColor;
		devModeColor = Frame.devModeColor;
		devMode = Frame.devMode;
	}


	void Frame::Update(bool UseInheritedScene)
	{
		if(UseInheritedScene)
		{
			inheritedScene->Update();
			for(int y = 0; y < sizeY; y++)
				for(int x = 0; x < sizeX; x++)
					grid[y][x] = inheritedScene->grid[y][x];
		}
		else
		{
			// Background
			if(!devMode)
			{
				for (int y = 0; y < sizeY; ++y)
					for (int x = 0; x < sizeX; ++x)
						grid[y][x] = fillColor;
			}
			else
			{
				bool Even = true;
				for (int y = 0; y < sizeY; ++y)
				{
					for (int x = 0; x < sizeX; ++x)
					{
						Even = !Even;
						if(Even)
							grid[y][x] = fillColor;
						else
							grid[y][x] = devModeColor;
					}
					if(sizeX % 2 == 0 && sizeY % 2 == 0)
						Even = !Even;
				}
			}
		}
		// Triangle Updating
		for(int y = 0; y < sizeY; y++)
			for(int x = 0; x < sizeX; x++)
				for(Triangle i : triangles)
					if(i.CheckCollision({x,y}) && !i.StartPos.IsEqual({x,y}))
						grid[y][x] = i.ch;

		// Cirlce Updating
		for(int y = 0; y < sizeY; y++)
			for(int x = 0; x < sizeX; x++)
				for(Circle i : circles)
					if(i.CheckCollision({x,y}))
						grid[y][x] = i.ch;
		
		// Rect Updating
		for(int y = 0; y < sizeX; y++)
			for(int x = 0; x < sizeY; x++)
				for(int Index = 0; Index < rects.size(); Index++)
					if(rects[Index].CheckCollision(Latno_Entities::Actor(x,y,'.',"...")))
						grid[y][x] = rects[Index].ch;
	}
	void Frame::Render()
	{
		int DevI = 0;

		std::string str;
		std::cout << std::endl;
		system("clear");
		
		if(devMode)
		{
			std::cout << "  ";
			for(int i = 0; i < sizeX; i++)
			{
				if(i < 10)
					std::cout << ' ' << i;
				else
					std::cout << i;
			}
			std::cout << std::endl << DevI << " ";
		}
			
		for(int y = 0; y < sizeY; y++)
		{
			for(int x = 0; x < sizeX; x++)
			{
				if(grid[y][x] == 'p')
					str = "\033[44m";
				else if(grid[y][x] == '.')
					str = "\033[47m";
				else if(grid[y][x] == 'e')
					str = "\033[41m";
				else if(grid[y][x] == '#')
					str = "\033[45m";
				else if(grid[y][x] == 'a')
						str = "\033[43m";
				else if(grid[y][x] == 'g')
					str = "\033[42m";
				else if(grid[y][x] == 'b')
					str = "\033[46m";
				else
					str = "\033[0m";
						
				std::cout << str + "  \033[0m";
			}
			if(devMode)
			{
				if(DevI < 9)
					std::cout << "\n" << ++DevI << " ";
				else if(DevI < sizeY - 1)
					std::cout << '\n' << ++DevI;
			}
			else 
			{
				std::cout << '\n';
			}
		}
	}
}