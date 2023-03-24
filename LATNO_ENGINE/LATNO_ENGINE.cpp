// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#define GLEW_STATIC
#include <glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// vvv AIDANS CODE FOR OPEN GL SHADERS vvv
static unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);


	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH,&length);

		// allocate memory on stack dynamically
		char* message = (char*)alloca(length * sizeof(char));

		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;

	}

	return id;

}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}





//#include "engine/declarations/Application.h"

int main()
{

	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Window Title", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return - 1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		std::cout << "ERROR!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;

	float positions[] = {
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.0f, 0.5f
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions,GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"}\n";
	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0,0.0,0.0,1.0);\n"
		"}\n";

	unsigned int shader = CreateShader(vertexShader,fragmentShader);
	glUseProgram(shader);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		

		// Swap front and back buffers
		glfwSwapBuffers(window);

		glfwPollEvents();
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
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

//int main()
//{
	//glfwInit();
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	//float vertices[] = {
	//	-0.5f, -0.5f, 0.0f,
	//	0.5f, -0.5f, 0.0f,
	//	0.0f, 0.5f, 0.0f
	//};

	//unsigned int VBO;
	//glGenBuffers(1, &VBO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	//GLFWwindow* window = glfwCreateWindow(800, 600, "learnopengl", NULL, NULL);
	//if (window == NULL)
	//{
	//	std::cout << "failed to create glfw window" << std::endl;
	//	glfwTerminate();
	//	return -1;
	//}

	//glfwMakeContextCurrent(window);
	//glViewport(0, 0, 800, 600);
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//if (glewInit() != GLEW_OK)
	//	std::cout << "ERROR!" << std::endl;

	//while (!glfwWindowShouldClose(window))
	//{
	//	processInput(window);
	//	
	//	render(window);

	//	glfwSwapBuffers(window);
	//	glfwPollEvents();
	//	

	//}

	//glfwTerminate();
	//	
	//return 0;
//}


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