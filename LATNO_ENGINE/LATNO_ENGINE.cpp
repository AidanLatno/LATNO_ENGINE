// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#define GLEW_STATIC
#include <glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


void processInput(GLFWwindow* window);

// struct that contains vertex and fragment shader
struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};


// Reads shader from file
static ShaderProgramSource ParseShader(const std::string& filepath)
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

// vvv AIDANS CODE FOR OPEN GL SHADERS vvv

// Compile shaders in memory so openGL knows how to use them
static unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);


	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) // if shader failed to compile
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH,&length);

		// allocate memory on stack dynamically
		char* message = (char*)alloca(length * sizeof(char));
		// char message[length]; <--- equivalent to
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;

	}

	return id;

}

// Creates instance of passed in shader in memory
static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
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

//#include "engine/declarations/Application.h"

int main()
{

	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	// vv Make GL Version core instead of compat vv
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// ^^ Make GL Version core instead of compat ^^


	window = glfwCreateWindow(640, 480, "Window Title", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return - 1;
	}

	glfwMakeContextCurrent(window);

	glfwSwapInterval(1); // Syncs swap interval with vsync

	if (glewInit() != GLEW_OK)
		std::cout << "ERROR!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;

	// Vertecies of triangles
	float positions[] = {
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.5f, 0.5f,
		-0.5f, 0.5f
	};

	// index buff for connecting points
	unsigned int indicies[] =
	{
		0,1,2,
		2,3,0
	};

	// vv Create and bind new vao vv
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	// ^^ Create and bind new vao ^^

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	unsigned int ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

	// Create shader
	ShaderProgramSource shaderSource = ParseShader("resources/shaders/Basic.shader");
	unsigned int shader = CreateShader(shaderSource.VertexSource, shaderSource.FragmentSource);
	glUseProgram(shader);

	// vv clear buffers vv
	glBindVertexArray(0);
	glUseProgram(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	// ^^ clear buffers ^^

	int location = glGetUniformLocation(shader, "u_Color");
	glUniform4f(location, 0.0f, 1.0f, 0.0f, 1.0f);


	float Red = 0.0f;
	float Green = 0.0f;
	float Blue = 0.0f;
	float increment = 0.05f;
	int count = 0;
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		// vv Re bind buffers every frame vv
		glUseProgram(shader);
		glBindVertexArray(vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		// ^^ Re bind buffers every frame ^^

		// vv Change colors vv
		if (Red > 1.0f)
			increment = -0.05f;
		else if(Red < 0.0f)
			increment = 0.05f;

		count++;

		Blue = abs(sin(count));
		Green = abs(cos(count));
		Red += increment;
		glUniform4f(location, Red, 1.0f, Blue, 1.0f); // set unifrom in shader 
		// ^^ Change colors ^^

		//draw call
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,nullptr);

		// Swap front and back buffers
		glfwSwapBuffers(window);

		glfwPollEvents();
		processInput(window);
	}
	glDeleteProgram(shader);
	glfwTerminate();
	return 0;




}
// ^^^ AIDANS CODE FOR OPEN GL SHADERS ^^^



// VVVVVVVVVVVV DEEP CODE VVVVVVVVVVVV

void render(GLFWwindow* window) {

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		std::cout << "SPACE PRESSED" << std::endl;

}

//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//
//	float vertices[] = {
//		-0.5f, -0.5f, 0.0f,
//		0.5f, -0.5f, 0.0f,
//		0.0f, 0.5f, 0.0f
//	};
//
//	unsigned int VBO;
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "learnopengl", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "failed to create glfw window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//	glViewport(0, 0, 800, 600);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	if (glewInit() != GLEW_OK)
//		std::cout << "ERROR!" << std::endl;
//
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//		
//		render(window);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//		
//
//	}
//
//	glfwTerminate();
//		
//	return 0;
//}
//
//
//#define GLFW_DLL
//#include <stdio.h>
//
//#include "engine/declarations/Application.h"
//#include "exceptions/declarations/RuntimeException.h"
//
//int main(void) {
//	DevLog MyLog("NewLog");
//
//	for (int i = 0; i < 100; i++)
//		MyLog.LOGLN("Your mother");
//
//
//
//	/* Initialize the library */
//	if (!glfwInit())
//		return -1;
//
//
//	GLFWwindow* window;
//	/* Create a windowed mode window and its OpenGL context */
//	window = glfwCreateWindow(640, 480, "WINDOW TITLE DEEP FRFR", NULL, NULL);
//
//
//	GLuint VertexArrayID;
//	glGenVertexArrays(1, &VertexArrayID);
//	glBindVertexArray(VertexArrayID);
//
//	static const GLfloat g_vertex_buffer_data[] = {
//		   -1.0f, -1.0f, 0.0f,
//		   1.0f, -1.0f, 0.0f,
//		   0.0f,  1.0f, 0.0f,
//	};
//
//	// This will identify our vertex buffer
//	GLuint vertexbuffer;
//	// Generate 1 buffer, put the resulting identifier in vertexbuffer
//	glGenBuffers(1, &vertexbuffer);
//	// The following commands will talk about our 'vertexbuffer' buffer
//	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//	// Give our vertices to OpenGL.
//	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//
//
//	if (!window)
//	{
//		glfwTerminate();
//		return -1;
//	}
//
//	/* Make the window's context current */
//	glfwMakeContextCurrent(window);
//
//	/* Loop until the user closes the window */
//	while (!glfwWindowShouldClose(window))
//	{
//		///* Render here */
//		//glClear(GL_COLOR_BUFFER_BIT);
//
//		//glBegin(GL_QUADS);
//		//glVertex2f(-0.5f, -0.5f);
//		//glVertex2f(-0.2f, 0.5f);
//		//glVertex2f(0.5f, -0.7f);
//		//glVertex2f(0.5f, -0.7f);
//		//glEnd();
//
//		///* Swap front and back buffers */
//		//glfwSwapBuffers(window);
//
//		///* Poll for and process events */
//		//glfwPollEvents();
//
//		// 1st attribute buffer : vertices
//		glEnableVertexAttribArray(0);
//		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//		glVertexAttribPointer(
//		   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
//		   3,                  // size
//		   GL_FLOAT,           // type
//		   GL_FALSE,           // normalized?
//		   0,                  // stride
//		   (void*)0            // array buffer offset
//		);
//		// Draw the triangle !
//		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
//		glDisableVertexAttribArray(0);
//	}
//
//	glfwTerminate();
//	return 0;
//
//	/*Application* app = new Application();
//
//	app->Startup();
//
//	delete app;*/
//}