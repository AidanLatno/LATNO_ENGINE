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

		m_VAO = std::make_unique<VertexArray>();

		m_VBO = std::make_unique<VertexBuffer>(positions, 16 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		m_VAO->AddBuffer(*m_VBO, layout);

		m_IBO = std::make_unique<IndexBuffer>(indicies, 6);

		m_IBO->Bind();

		m_Shader = std::make_unique<Shader>("resources/shaders/Basic.shader");
		m_Shader->Bind();

		m_Texture = std::make_unique<Texture>("resources/textures/Test.png");
		m_Texture->Bind();
		m_Shader->SetUniform1i("u_Texture", 0);
	}

	void TestBuffer::OnUpdate(float deltaTime)
	{

	}

	void TestBuffer::OnRender() 
	{
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
		
		glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translation);
		glm::mat4 mvp = m_projection * m_view * model; // (Model View Projection)
		//m_Shader->SetUniformMat4f("u_ViewProj", mvp);

		m_Shader->SetUniformMat4f("u_ModelViewProjectionMatrix", mvp);

		m_Shader->Bind();
		m_VAO->Bind();
		m_IBO->Bind();

	/*	m_Shader->SetUniformMat4f("u_Transform", glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)));
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);*/
		//m_Shader->SetUniformMat4f("u_Transform", glm::translate(glm::mat4(1.0f), glm::vec3(10.0f, 10.0f, 0.0f)));
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
	}


	void TestBuffer::OnImGuiRender() {

	}
}