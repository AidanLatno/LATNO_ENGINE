#pragma once

//Screen size
#define WINDOW_HEIGHT 1440
#define WINDOW_LENGTH 1920

// DO NOT REMOVE
// ENABLES STATIC LINKING WITH GLEW LIBRARY
#define GLEW_STATIC
#include <glew.h>
#include <GLFW/glfw3.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#define CLEAR_SCREEN system("cls")

inline void usleep(__int64 usec) 
{ 
    HANDLE timer; 
    LARGE_INTEGER ft;

    ft.QuadPart = -(10*usec); // Convert to 100 nanosecond interval, negative value indicates relative time

    timer = CreateWaitableTimer(NULL, TRUE, NULL);
    if (timer != 0)
    {
        SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
        WaitForSingleObject(timer, INFINITE);
        CloseHandle(timer);
    }
}
#endif

#ifdef __APPLE__
#define getch getchar
#include <unistd.h>
#define CLEAR_SCREEN system("clear")
#endif

#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#define CLEAR_SCREEN system("clear")
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
#include <unordered_map>
#include "Behavior.h"



#define UP Coords(0,1)
#define DOWN Coords(0,-1)
#define RIGHT Coords(1,0)
#define LEFT Coords(-1,0)

inline char GetInput()
{
    if (_kbhit())
    {
        return _getch();
    }
    return NULL;
}