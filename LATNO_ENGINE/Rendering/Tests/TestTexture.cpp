#include "TestTexture.h"

#include "../Renderer.h"
#include "ImGui/imgui.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


namespace test
{
	test::TestTexture::TestTexture()
		: m_translationA(200,200,0),
		  m_translationB(400,200,0),
		  m_projection(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f)),
		  m_view(glm::translate(glm::mat4(1.0f),glm::vec3(0, 0, 0)))
	{

		float positions[] = {
			-50.0f, -50.0f, 0.0f, 0.0f, // 0 - bottom left
			50.0f, -50.0f, 1.0f, 0.0f, // 1 - bottom right
			50.0f, 50.0f, 1.0f, 1.0f, // 2 - top right
			-50.0f, 50.0f, 0.0f, 1.0f // 3 - top left
		};

		// index buff for connecting points
		unsigned int indicies[] =
		{
			0,1,2,
			2,3,0
		};
		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		
		m_VAO = std::make_unique<VertexArray>();
		

		VertexArray va;

		m_VBO = std::make_unique<VertexBuffer>(positions, 4 * 4 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		m_VAO->AddBuffer(*m_VBO, layout);
		m_IBO = std::make_unique<IndexBuffer>(indicies, 6);

		IndexBuffer ib(indicies, 6);

		m_Shader = std::make_unique<Shader>("resources/shaders/Basic.shader");
		m_Shader->Bind();
		m_Shader->SetUniform4f("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);

		m_TextureCherno = std::make_unique<Texture>("resources/textures/cherno.png");
		m_Shader->SetUniform1i("u_Texture", 0);

		m_TextureSprite = std::make_unique<Texture>("resources/textures/sp.png");

	}

	test::TestTexture::~TestTexture()
	{
	}

	void test::TestTexture::OnUpdate(float deltaTime)
	{
	}

	void test::TestTexture::OnRender()
	{
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		Renderer renderer;

		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_W) == GLFW_PRESS)
		{
			m_translationA.y++;
		}
		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_A) == GLFW_PRESS)
		{
			m_translationA.x--;
		}
		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_S) == GLFW_PRESS)
		{
			m_translationA.y--;
		}
		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_D) == GLFW_PRESS)
		{
			m_translationA.x++;
		}

		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_UP) == GLFW_PRESS)
		{
			m_translationB.y++;
		}
		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_LEFT) == GLFW_PRESS)
		{
			m_translationB.x--;
		}
		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			m_translationB.y--;
		}
		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_RIGHT) == GLFW_PRESS)
		{
			m_translationB.x++;
		}

		m_TextureCherno->Bind();

		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationA);
			glm::mat4 mvp = m_projection * m_view * model; // (Model View Projection)
			m_Shader->Bind(); // Re bind shader every frame
			m_TextureCherno->Bind();
			m_Shader->SetUniform1i("u_Texture", 0);
			m_Shader->SetUniformMat4f("u_ModelViewProjectionMatrix", mvp);

			renderer.Draw(*m_VAO, *m_IBO, *m_Shader);
		}
		// ^^^ FIRST OBJECT DRAW ^^^


		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationB);
			glm::mat4 mvp = m_projection * m_view * model; // (Model View Projection)
			m_Shader->Bind(); // Re bind shader every frame
			m_TextureSprite->Bind(); // Re bind shader every frame
			m_Shader->SetUniform1i("u_Texture", 0);
			m_Shader->SetUniformMat4f("u_ModelViewProjectionMatrix", mvp);
			renderer.Draw(*m_VAO, *m_IBO, *m_Shader);
		}
	}

	void test::TestTexture::OnImGuiRender()
	{
		ImGui::SliderFloat2("translationA", &m_translationA.x, 0.0f, 960.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
		ImGui::SliderFloat2("translationB", &m_translationB.x, 0.0f, 960.0f);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}