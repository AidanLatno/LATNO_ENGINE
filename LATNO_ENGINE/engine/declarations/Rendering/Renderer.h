#pragma once

#include <glew.h>
#include <sstream>
#include "../DeveloperLog.h"

#include "VertexBufferlayout.h"
#include "IndexBuffer.h"
#include "Sprite.h"

class Renderer
{
private:
	//Sprite[] sprites; //but a vector (list)
public:
	void Clear() const;


	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const; 
};