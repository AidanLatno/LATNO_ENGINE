#include "../declarations/Renderer.h"

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	std::stringstream stream;
	while (GLenum error = glGetError())
	{
		stream << "[OpenGL Error] (" << error << "): " << function << " " << file << ": " << line;
		DevLog::LOGLN(stream.str(), "GL_ERROR_LOG");
		std::cout << stream.str();
		return false;
	}
	return true;
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
