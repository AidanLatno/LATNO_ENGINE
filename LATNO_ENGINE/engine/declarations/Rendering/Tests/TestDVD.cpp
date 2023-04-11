#include "TestDVD.h"
#include "../VertexBufferLayout.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ImGui/imgui.h"

namespace test
{
	TestDVD::TestDVD()
		: m_projection(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f)),
		  m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)))
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

		m_IBO->Bind();

		m_Shader = std::make_unique<Shader>("resources/shaders/Basic.shader");
		m_Shader->Bind();

		m_TextureDVD = std::make_unique<Texture>("resources/textures/cherno.png");
		m_TextureDVD->Bind();
		m_Shader->SetUniform1i("u_Texture", 0);

		direction = { 10,10 };
	}

	void TestDVD::OnUpdate(float deltaTime)
	{
		if (m_translation.x > 930)
			direction.x =  -moveSpeed;
		else if (m_translation.x < 30)
			direction.x = moveSpeed;
		else if (m_translation.y > 510)
			direction.y = -moveSpeed;
		else if (m_translation.y < 30)
			direction.y = moveSpeed;

		if((m_translation.x == 0 && m_translation.y == 0)
			|| (m_translation.x == 960 && m_translation.y == 560)
			|| (m_translation.x == 0 && m_translation.y == 560)
			|| (m_translation.x == 960 && m_translation.y == 0))
		{
			std::cout << "CORNER";
		}

		m_translation.x += direction.x;
		m_translation.y += direction.y;
	}

	void TestDVD::OnRender()
	{
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		Renderer renderer;
		{
						glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translation);
glm::mat4 mvp = m_projection * m_view * model; // (Model View Projection)
			m_TextureDVD->Bind();
			m_Shader->SetUniform1i("u_Texture", 0);
			m_Shader->SetUniformMat4f("u_ModelViewProjectionMatrix", mvp);

			renderer.Draw(*m_VAO, *m_IBO, *m_Shader);
		}

	}

	void TestDVD::OnImGuiRender()
	{
		ImGui::SliderFloat2("Position", &m_translation.x, 0.0f, 960.0f);
		ImGui::SliderInt("Speed", &moveSpeed, 0, 530);
	}
}