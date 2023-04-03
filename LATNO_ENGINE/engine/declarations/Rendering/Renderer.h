#pragma once

#include <glew.h>
#include <sstream>
#include "../DeveloperLog.h"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Sprite.h"

#define ASSERT(x) if (!(x)) __debugbreak()
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x,__FILE__,__LINE__))

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{
private:
	//Sprite[] sprites; //but a vector (list)
public:
	void Clear() const;

	Sprite initSprite(Sprite toInit);

	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const; 
};