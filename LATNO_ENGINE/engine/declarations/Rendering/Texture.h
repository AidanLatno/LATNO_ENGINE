#pragma once
#include "Shader.h"

class Texture
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;

public:
	Texture(const std::string& path);
	Texture();
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	inline std::string GetPath() const { return m_FilePath; }
	inline unsigned int GetID() const { return m_RendererID; }

};