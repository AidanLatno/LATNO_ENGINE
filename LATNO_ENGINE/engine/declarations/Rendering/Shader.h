#pragma once
#include <string>
#include <unordered_map>

#include "glm/glm.hpp"

// struct that contains vertex and fragment shader
struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	unsigned int GetRendererID();
	void Unbind() const;

	// set uniforms
	void SetUniform1f(const std::string& name, float value); // takes in single float
	void SetUniform1i(const std::string& name, int value); // takes in single int

	void SetUniform3f(const std::string& name, float x, float y, float z);
	void SetUniform3f(const std::string& name, const glm::vec3& value);

	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3); // takes in 4 floats (vec4)
	void SetUniformMat4f(const std::string& name, const glm::mat4 matrix); // takes in mat4(glm library) for matrix projection
	void SetUniformMat4(unsigned int shader, const char* name, const glm::mat4& matrix);
private:
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderProgramSource ParseShader(const std::string& filepath);

	int GetUniformLocation(const std::string& name);
};