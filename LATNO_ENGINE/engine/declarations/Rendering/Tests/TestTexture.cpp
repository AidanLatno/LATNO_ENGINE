#include "TestTexture.h"

#include "../Renderer.h"
#include "ImGui/imgui.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "../Shapes/declarations/Rect.h"


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

		m_VBO = std::make_unique<VertexBuffer>(positions, 4 * 4 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		m_VAO->AddBuffer(*m_VBO, layout);
		m_IBO = std::make_unique<IndexBuffer>(indicies, 6);

		m_Shader = std::make_unique<Shader>("resources/shaders/Basic.shader");
		m_Shader->Bind();

		m_TextureCherno = std::make_unique<Texture>("resources/textures/grr.png");
		m_Shader->SetUniform1i("u_Texture", 0);

		m_TextureSprite = std::make_unique<Texture>("resources/textures/ahh.png");
		m_Enemy = std::make_unique<Texture>("resources/textures/sp.png");


	}

	test::TestTexture::~TestTexture()
	{
	}

	void test::TestTexture::OnUpdate(float deltaTime)
	{
		if (CooldownA > 0)
			CooldownA -= 1 / deltaTime;
		if (CooldownB > 0)
			CooldownB -= 1 / deltaTime;

		if (m_translationC.x < m_translationB.x)
			m_translationC.x += 30 / deltaTime;
		else if (m_translationC.x > m_translationB.x)
			m_translationC.x -= 30 / deltaTime;
		if (m_translationC.y < m_translationB.y)
			m_translationC.y += 30 / deltaTime;
		else if (m_translationC.y > m_translationB.y)
			m_translationC.y -= 30 / deltaTime;

		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_SPACE) == GLFW_PRESS && CooldownA <= 0)
		{
			if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_W) == GLFW_PRESS)
			{
				m_translationA.y += 6000 / deltaTime;
			}
			if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_A) == GLFW_PRESS)
			{
				m_translationA.x -= 6000 / deltaTime;
			}
			if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_S) == GLFW_PRESS)
			{
				m_translationA.y -= 6000 / deltaTime;
			}
			if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_D) == GLFW_PRESS)
			{
				m_translationA.x += 6000 / deltaTime;
			}
			CooldownA = 10;
		}

		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS && CooldownB <= 0)
		{
			if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_UP) == GLFW_PRESS)
			{
				m_translationB.y += 9000 / deltaTime;
			}
			if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_LEFT) == GLFW_PRESS)
			{
				m_translationB.x -= 9000 / deltaTime;
			}
			if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_DOWN) == GLFW_PRESS)
			{
				m_translationB.y -= 9000 / deltaTime;
			}
			if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_RIGHT) == GLFW_PRESS)
			{
				m_translationB.x += 9000 / deltaTime;
			}
			CooldownB = 10;
		}

		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_W) == GLFW_PRESS)
		{
			if (m_translationA.y < 510)
				m_translationA.y += 200 / deltaTime;
		}
		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_A) == GLFW_PRESS)
		{
			if (m_translationA.x > 30)
				m_translationA.x -= 200 / deltaTime;
		}
		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_S) == GLFW_PRESS)
		{
			if (m_translationA.y > 30)
				m_translationA.y -= 200 / deltaTime;
		}
		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_D) == GLFW_PRESS)
		{
			if (m_translationA.x < 930)
				m_translationA.x += 200 / deltaTime;
		}

		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_UP) == GLFW_PRESS)
		{
			if(m_translationB.y < 510)
				m_translationB.y += 300 / deltaTime;
		}
		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_LEFT) == GLFW_PRESS)
		{
			if(m_translationB.x > 30)
				m_translationB.x -= 300 / deltaTime;
		}
		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			if (m_translationB.y > 30)
				m_translationB.y -= 300 / deltaTime;
		}
		if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_RIGHT) == GLFW_PRESS)
		{
			if (m_translationB.x < 930)
				m_translationB.x += 300 / deltaTime;
		}

		color = glm::vec4(0.0, 0.0, 0.0, 1.0);

		Rect bounds(m_translationA.x - 30, m_translationA.y - 30, m_translationA.x + 30, m_translationA.y + 30, 'e', "ASDAd");
		Rect boundsEnemy(m_translationC.x - 30, m_translationC.y - 30, m_translationC.x + 30, m_translationC.y + 30, 'e', "ASDAd");
		Rect scoreBounds(m_translationA.x - 90, m_translationA.y - 90, m_translationA.x + 90, m_translationA.y + 90, 'e', "ASDAd");
		if (scoreBounds.CheckCollision({ static_cast<int>(m_translationB.x),static_cast<int>(m_translationB.y) }))
			score += 1 / deltaTime;

		if (bounds.CheckCollision({ static_cast<int>(m_translationB.x),static_cast<int>(m_translationB.y) })
			|| boundsEnemy.CheckCollision({ static_cast<int>(m_translationB.x),static_cast<int>(m_translationB.y) }))
		{
			if(score > 1)
				std::cout << "YOU DIED, YOUR SCORE WAS " << score << "\n";
			score = 0;
			color = glm::vec4(1.0, 0.0, 0.0, 1.0);
		}
			
	}

	void test::TestTexture::OnRender()
	{
		GLCall(glClearColor(color[0], color[1], color[2], color[3] ));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		Renderer renderer;

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
			glm::mat4 model = glm::translate(glm::mat4(2.0f), m_translationB);
			glm::mat4 mvp = m_projection * m_view * model; // (Model View Projection)
			m_Shader->Bind(); // Re bind shader every frame
			m_TextureSprite->Bind(); // Re bind shader every frame
			m_Shader->SetUniform1i("u_Texture", 0);
			m_Shader->SetUniformMat4f("u_ModelViewProjectionMatrix", mvp);
			renderer.Draw(*m_VAO, *m_IBO, *m_Shader);
		}

		{
			glm::mat4 model = glm::translate(glm::mat4(2.0f), m_translationC);
			glm::mat4 mvp = m_projection * m_view * model; // (Model View Projection)
			m_Shader->Bind(); // Re bind shader every frame
			m_Enemy->Bind(); // Re bind shader every frame
			m_Shader->SetUniform1i("u_Texture", 0);
			m_Shader->SetUniformMat4f("u_ModelViewProjectionMatrix", mvp);
			renderer.Draw(*m_VAO, *m_IBO, *m_Shader);
		}
	}

	void test::TestTexture::OnImGuiRender()
	{
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

		ImGui::Text("COOL DOWN FOR C: %.3f", CooldownA);

		ImGui::Text("COOL DOWN FOR SPRITE: %.3f", CooldownB);

		ImGui::Text("SCORE: %.2f", score);
	}
}
