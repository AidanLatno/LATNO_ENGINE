#pragma once

// SCREEN SIZE (Change to fit your application)
#define WINDOW_HEIGHT 1080
#define WINDOW_LENGTH 1920


// ENABLE STATIC LINKING WITH GLEW AND GLFW LIBRARY
#define GLEW_STATIC
#include <glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp" // include glm (openGL math library)

// Extra definitions for apple (Probably doesnt work)
#ifdef __APPLE__
#include <unistd.h>
#endif

// Extra definitions for linux (Also probably doesnt work)
#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#endif

// Basic includes
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include "Behavior.h"


// Definitions for directions
#define UP Coords(0,1)
#define DOWN Coords(0,-1)
#define RIGHT Coords(1,0)
#define LEFT Coords(-1,0)

extern double GLOBAL_DELTA_TIME;

//
// BM--------------------------------------------------------------------------------------------------------------
// mouse movement+ and cursor output
typedef struct
{
    GLFWwindow* window;
    int number;
    int closeable;
} Slot;

static unsigned int counter = 0;

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
