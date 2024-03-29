#pragma once
#include "GL_Definitions.h"

class IndexBuffer
{
private:
	unsigned int m_RendererID; // ID that refers to OpenGL as the renderer
	unsigned int m_Count;
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return m_Count;  }
};