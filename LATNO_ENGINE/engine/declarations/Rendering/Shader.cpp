#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "Renderer.h"
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& filepath)
	: m_FilePath(filepath)
{
	ShaderProgramSource shaderSource = Shader::ParseShader(filepath);
	m_RendererID = CreateShader(shaderSource.VertexSource, shaderSource.FragmentSource);
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(m_RendererID));
}


// Reads shader from file
ShaderProgramSource Shader::ParseShader(const std::string& filepath)
{
	std::ifstream stream(filepath);

	enum class ShaderType
	{
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1
	};


	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << '\n';
		}
	}
	return { ss[0].str(),ss[1].str() };
}

// Compile shaders in memory so openGL knows how to use them
unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
	GLCall(unsigned int id = glCreateShader(type));
	const char* src = source.c_str();
	GLCall(glShaderSource(id, 1, &src, nullptr));
	GLCall(glCompileShader(id));


	int result;
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if (result == GL_FALSE) // if shader failed to compile
	{
		std::stringstream stream;
		int length;
		GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));

		// allocate memory on stack dynamically
		char* message = (char*)alloca(length * sizeof(char));
		// char message[length]; <--- equivalent to
		GLCall(glGetShaderInfoLog(id, length, &length, message));
		stream << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!";
		DevLog::LOGLN(stream.str(), "GL_ERROR_LOG");
		DevLog::LOGLN(message, "GL_ERROR_LOG");
		std::cout << stream.str() << '\n';
		std::cout << message << std::endl;

		GLCall(glDeleteShader(id));
		return 0;

	}

	return id;

}

// Creates instance of passed in shader in memory
unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vertex = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fragment = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	GLCall(glAttachShader(program, vertex));
	GLCall(glAttachShader(program, fragment));
	GLCall(glLinkProgram(program));
	GLCall(glValidateProgram(program));

	GLCall(glDeleteShader(vertex));
	GLCall(glDeleteShader(fragment));

	return program;
}

void Shader::Bind() const
{
	GLCall(glUseProgram(m_RendererID));
}

unsigned int Shader::GetRendererID()
{
	return m_RendererID;
}

void Shader::Unbind() const
{

	GLCall(glUseProgram(0));
}

void Shader::SetUniform1f(const std::string& name, float value)
{

	GLCall(glUniform1f(GetUniformLocation(name), value));
}

void Shader::SetUniform1i(const std::string& name, int value)
{

	GLCall(glUniform1i(GetUniformLocation(name), value));
}

void Shader::SetUniform3f(const std::string& name, float x, float y, float z)
{
	GLCall(glUniform3f(GetUniformLocation(name), x, y, z));
}
void Shader::SetUniform3f(const std::string& name, const glm::vec3& value)
{
	GLCall(glUniform3f(GetUniformLocation(name), value.x, value.y, value.z));
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{

	GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4 matrix)
{
	GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
}

void Shader::SetUniformMat4(unsigned int shader, const char* name, const glm::mat4& matrix)
{
	int loc = glGetUniformLocation(shader, name);
	GLCall(glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(matrix)));
}

int Shader::GetUniformLocation(const std::string& name)
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];

	GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
	if (location == -1)
		DevLog::LOGLN("Warning: uniform '" + name + "' doesn't exist!", "GL_ERROR_LOG");
	
	m_UniformLocationCache[name] = location;
	return location;
}

unsigned int Shader::GetID()
{
	return m_RendererID;
}