#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "Renderer.h"

Shader::Shader(const std::string& filepath)
	: m_FilePath(filepath)
{
	ShaderProgramSource shaderSource = ParseShader("resources/shaders/Basic.shader");
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
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);


	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) // if shader failed to compile
	{
		std::stringstream stream;
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

		// allocate memory on stack dynamically
		char* message = (char*)alloca(length * sizeof(char));
		// char message[length]; <--- equivalent to
		glGetShaderInfoLog(id, length, &length, message);
		stream << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!";
		DevLog::LOGLN(stream.str(), "GL_ERROR_LOG");
		DevLog(message, "GL_ERROR_LOG");
		std::cout << stream.str() << '\n';
		std::cout << message << std::endl;

		glDeleteShader(id);
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

	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return program;
}

void Shader::Bind() const
{
	GLCall(glUseProgram(m_RendererID));
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

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{

	GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
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
