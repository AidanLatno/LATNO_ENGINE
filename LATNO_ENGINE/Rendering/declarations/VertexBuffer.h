#pragma once

class VertexBuffer
{
private:
	unsigned int m_RendererID; // ID that refers to OpenGL as the renderer
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};