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
		m_Shader = std::make_unique<Shader>("resources/shaders/Basic.shader");
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		float verticies[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,
		};

		m_VAO = std::make_unique<VertexArray>();
		//glGenVertexArrays(1, &m_RendererID);

		m_VAO->Bind();
		//glBindVertexArray(m_RendererID);

		m_VBO = std::make_unique<VertexBuffer>(verticies, sizeof(verticies));
		/*
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		*/

		// I copied this cause i still dont understand bufferlayout
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		m_VAO->AddBuffer(*m_VBO, layout);

		uint32_t indicies[] = {
			0, 1, 2, 2, 3, 0
		};
		//                                             we only need size of indicies but method multiplies it by sizeof(unsigned int)
		m_IBO = std::make_unique<IndexBuffer>(indicies, sizeof(indicies));
		m_IBO->Bind();
		/*
		glGenBuffers(1, &m_RendererID));
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
		*/

		


	}

	void TestBuffer::OnUpdate(float deltaTime)
	{

	}

	void TestBuffer::OnRender() 
	{
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		m_Shader->Bind();
		Renderer renderer;

		m_Shader->GetRendererID();

		m_Shader->SetUniformMat4f("u_Transform", glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)));

		glm::mat4 vp = m_projection * m_view;
		m_Shader->SetUniformMat4f("u_ViewProj", vp);

		renderer.Draw(*m_VAO, *m_IBO, *m_Shader);
		
		m_VAO->Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		
	}
	void TestBuffer::OnImGuiRender() {}
}