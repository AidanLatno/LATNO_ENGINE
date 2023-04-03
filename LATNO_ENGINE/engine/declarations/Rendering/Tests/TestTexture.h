#pragma once
#include "Test.h"

#include "../VertexBuffer.h"
#include "../VertexBufferLayout.h"
#include "../Texture.h"

#include <memory>

namespace test
{
	class TestTexture : public Test
	{
	public:
		TestTexture();
		~TestTexture();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;
	private:
		std::unique_ptr<VertexArray> m_VAO;
		std::unique_ptr<VertexBuffer> m_VBO;
		std::unique_ptr <IndexBuffer> m_IBO;
		std::unique_ptr <Shader> m_Shader;
		std::unique_ptr<Texture> m_TextureCherno;
		std::unique_ptr<Texture> m_TextureSprite;
		float CooldownA, CooldownB;
		glm::mat4 m_projection,m_view;
		glm::vec3 m_translationA, m_translationB;
	};
}