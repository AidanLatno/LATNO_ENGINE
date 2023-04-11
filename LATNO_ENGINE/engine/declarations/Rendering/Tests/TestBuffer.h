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

		std::unique_ptr<VertexArray> m_VAO;
		std::unique_ptr<VertexBuffer> m_VBO;
		std::unique_ptr<IndexBuffer> m_IBO;
		std::unique_ptr<Shader> m_Shader;

		glm::mat4 m_projection, m_view;

	};
}