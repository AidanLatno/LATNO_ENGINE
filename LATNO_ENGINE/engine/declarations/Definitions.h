#pragma once

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#endif

#ifdef __APPLE__
#define getch getchar
#include <unistd.h>
#endif

#ifdef __linux__
#include <termios.h>
#include <unistd.h>
char getch()
{
  char buf = 0;
  struct termios old = {0};
  if(tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if(tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
  if(read(0, &buf, 1) < 0)
    perror("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if(tcsetattr(0, TCSADRAIN, &old) < 0)
    perror("tcsetattr ~ICANON");
  return (buf);
}
#endif

#include <iostream>

#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include <vector>
#include <math.h>
#include "DeveloperLog.h"



#define UP Coords(0,-1)
#define DOWN Coords(0,1)
#define RIGHT Coords(1,0)
#define LEFT Coords(-1,0)

std::ofstream Builder("SAVEDATA.txt");
std::fstream SaveFile;



// red,blue,empty or white,void or black,purple,yellow,green,cyan
char ToChar(std::string Color)
{
	if(Color == "red") return 'e';
	else if(Color == "blue") return 'p';
	else if(Color == "empty" || Color == "white") return '.';
	else if(Color == "purple") return '#';
	else if(Color == "yellow") return 'a';
	else if(Color == "green") return 'g';
	else if(Color == "cyan") return 'b';
	else if(Color == "void" || Color == "black") return 'v';
	return '.';
}

static void SlowPrint(const std::string message, int milPerChar = 60)
{
  for (const char c : message)
	{
    std::cout << c << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(milPerChar));
  }
}