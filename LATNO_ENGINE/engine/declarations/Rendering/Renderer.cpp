#include "Renderer.h"

Renderer::Renderer()
	: m_translation(200, 200, 0),
	  m_projection(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f)),
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

}

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
		shader.Bind();
		va.Bind();
		ib.Bind();

		GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::RenderSprites(GLFWwindow* window) const
{
	GLCall(glClearColor(1.0f,1.0f,1.0f,1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));

	for (Sprite* sprite : sprites)
	{
		glm::mat4 model = glm::translate(glm::mat4(2.0f), sprite->Position);
		glm::mat4 mvp = m_projection * m_view * model; // (Model View Projection)
		sprite->shader->Bind(); // Re bind shader every frame
		sprite->texture->Bind(); // Re bind shader every frame
		sprite->shader->SetUniform1i("u_Texture", 0);
		sprite->shader->SetUniformMat4f("u_ModelViewProjectionMatrix", mvp);
		Draw(*m_VAO, *m_IBO, *(sprite->shader));
	}
}

 void Renderer::AddSprite(Sprite* sprite)
 {
	 sprites.push_back(sprite);
 }
