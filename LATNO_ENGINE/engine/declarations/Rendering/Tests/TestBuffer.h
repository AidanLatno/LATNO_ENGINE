#pragma once

#include "Test.h"
#include "../VertexArray.h"
#include "../Texture.h"
#include "../IndexBuffer.h"

namespace test 
{

	class TestBuffer : public Test
	{
	public:
		TestBuffer();
		~TestBuffer();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:

		unsigned int m_VAO;
		unsigned int m_VBO;
		unsigned int m_IBO;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<Texture> m_Texture;

		glm::mat4 m_projection, m_view;
        glm::vec3 m_translation;

	};
}