#pragma once

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



#define UP Coords(0,-1)
#define DOWN Coords(0,1)
#define RIGHT Coords(1,0)
#define LEFT Coords(-1,0)


const std::unordered_map<char, std::string> escape_codes =
{
    { 'p', "\033[44m" },
    { '.', "\033[47m" },
    { 'e', "\033[41m" },
    { '#', "\033[45m" },
    { 'a', "\033[43m" },
    { 'g', "\033[42m" },
    { 'b', "\033[46m" }
};

inline void SlowPrint(const std::string message, int milPerChar = 60)
{
    for (const char c : message)
    {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(milPerChar));
    }
}
// red,blue,empty or white,void or black,purple,yellow,green,cyan
inline char ToChar(std::string Color)
{
    if (Color == "red") return 'e';
    else if (Color == "blue") return 'p';
    else if (Color == "empty" || Color == "white") return '.';
    else if (Color == "purple") return '#';
    else if (Color == "yellow") return 'a';
    else if (Color == "green") return 'g';
    else if (Color == "cyan") return 'b';
    else if (Color == "void" || Color == "black") return 'v';
    return '.';
}

inline char GetInput()
{
    if (_kbhit())
    {
        return _getch();
    }
    return NULL;
}