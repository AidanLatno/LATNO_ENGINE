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
		float verticies[] = {
			-50.0f, -50.0f, 0.0f,
			 50.0f, -50.0f, 0.0f,
			 50.0f,  50.0f, 0.0f,
			-50.0f,  50.0f, 0.0f,
		};


		unsigned int indicies[] = {
			0, 1, 2,
			2, 3, 0
		};

		m_VAO = std::make_unique<VertexArray>();
		//glGenVertexArrays(1, &m_RendererID);

		//m_VAO->Bind();
		//glBindVertexArray(m_RendererID)

		m_VBO = std::make_unique<VertexBuffer>(verticies, 16 * sizeof(float));
		/*
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		*/																																																

		// I copied this cause i still dont understand bufferlayout
		VertexBufferLayout layout;
		layout.Push<float>(3);

		m_VAO->AddBuffer(*m_VBO, layout);
		//glEnableVertexArrayAttrib(m_VBO, 0);
		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		m_IBO = std::make_unique<IndexBuffer>(indicies, 6);

		m_Shader = std::make_unique<Shader>("resources/shaders/Basic.shader");
		m_Shader->Bind();
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

		
		auto vp = m_projection * m_view;
		m_Shader->SetUniformMat4f("u_ViewProj", vp);
		
		//m_VAO->Bind();

		m_Shader->SetUniformMat4f("u_Transform", glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)));
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		//m_Shader->SetUniformMat4f("u_Transform", glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}


	void TestBuffer::OnImGuiRender() {}
}