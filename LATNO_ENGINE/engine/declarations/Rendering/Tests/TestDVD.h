#pragma once

#include "Test.h"
#include "../Renderer.h"
#include "../engine/declarations/Coords.h"

namespace test
{

	class TestDVD : public Test
	{
	public:
		TestDVD();
		~TestDVD() {}

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;
	private:
		Coords direction;
		std::unique_ptr<VertexArray> m_VAO;
		std::unique_ptr<VertexBuffer> m_VBO;
		std::unique_ptr <IndexBuffer> m_IBO;
		std::unique_ptr <Shader> m_Shader;
		std::unique_ptr<Texture> m_TextureDVD;
		int moveSpeed = 10;
		glm::mat4 m_projection, m_view;
		glm::vec3 m_translation;
	};

}