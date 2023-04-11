#include "TestBuffer.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ImGui/imgui.h"

namespace test
{

	TestBuffer::~TestBuffer() {}

	TestBuffer::TestBuffer() : 
		m_projection(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f)),
		m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)))
		//^ copied this cause i saw it from DVD and needed it here (but i get what it does)
	{
		m_translation = glm::vec3(50.0f, 50.0f, 0.0f);

		float verticies[] = {
			-50.0f, -50.0f, 0.0f, // 0 - bottom left
			 50.0f, -50.0f, 0.0f, // 1 - bottom right
			 50.0f,  50.0f, 0.0f, // 2 - top right
			-50.0f,  50.0f, 0.0f // 3 - top left
		};

		// index buff for connecting points
		unsigned int indicies[] =
		{
			0,1,2,
			2,3,0
		};

		//m_VAO = std::make_unique<VertexArray>();
		glCreateVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);

		//m_VBO = std::make_unique<VertexBuffer>(positions, 16 * sizeof(float));
		glCreateBuffers(1, &m_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

		glEnableVertexArrayAttrib(m_VBO, 0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

		glCreateBuffers(1, &m_IBO);
		glBindBuffer(GL_ARRAY_BUFFER, m_IBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);
	
		m_Shader = std::make_unique<Shader>("resources/shaders/Batch.shader");
	}

	void TestBuffer::OnUpdate(float deltaTime)
	{
		OnRender();
	}

	void TestBuffer::OnRender() 
	{
		GLCall(glClearColor(1.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));


		glUseProgram(m_Shader->GetRendererID());

		auto vp = m_view * m_projection;

		m_Shader->SetUniformMat4(m_Shader->GetRendererID(), "u_ViewProj", vp);
		m_Shader->SetUniformMat4(m_Shader->GetRendererID(), "u_Transform",
					glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)));

		glBindVertexArray(m_VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}


	void TestBuffer::OnImGuiRender() {

	}
}