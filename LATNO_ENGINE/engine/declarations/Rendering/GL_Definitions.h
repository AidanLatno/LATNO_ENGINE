#pragma once
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <glew.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


#include "../../../vendor/stb_img/stb_image.h"

#include <sstream>
#include "../Definitions.h"

inline void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

inline bool GLLogCall(const char* function, const char* file, int line)
{
	std::stringstream stream;
	while (GLenum error = glGetError())
	{
		stream << "[OpenGL Error] (" << error << "): " << function << " " << file << ": " << line;
		Latno::DevLog::LOGLN(stream.str(), "GL_ERROR_LOG");
		std::cout << stream.str();
		return false;
	}
	return true;
}

#define ASSERT(x) if (!(x)) __debugbreak()
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x,__FILE__,__LINE__))
