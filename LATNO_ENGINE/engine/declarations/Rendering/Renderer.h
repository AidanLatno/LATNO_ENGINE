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
	std::vector<Sprite*> sprites;
public:
	Renderer();
	void Clear() const;
	void AddSprite(Sprite* sprite);
	void RenderSprites(GLFWwindow* window) const;
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const; 
// temp stuffs

	glm::vec3 m_translation;
private:
	std::unique_ptr<VertexArray> m_VAO;
	std::unique_ptr<VertexBuffer> m_VBO;
	std::unique_ptr <IndexBuffer> m_IBO;
	glm::mat4 m_projection, m_view;
	
};