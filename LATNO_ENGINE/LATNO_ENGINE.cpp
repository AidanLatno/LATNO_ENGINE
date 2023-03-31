// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#define GLEW_STATIC
#include <glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "engine/declarations/DeveloperLog.h"

#include "engine/declarations/Rendering/VertexArray.h"
#include "engine/declarations/Rendering/IndexBuffer.h"
#include "engine/declarations/Rendering/VertexBufferLayout.h"
#include "engine/declarations/Rendering/Shader.h"
#include "engine/declarations/Rendering/Texture.h"


bool processInput(GLFWwindow* window);


// vvv AIDANS CODE FOR OPEN GL SHADERS vvv

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
		-0.5f, -0.5f, 0.0f, 0.0f, // 0
		0.5f, -0.5f, 1.0f, 1.0f, // 1
		0.5f, 0.5f, 1.0f, 1.0f, // 2
		-0.5f, 0.5f, 0.0f, 1.0f // 3
	};

	// index buff for connecting points
	unsigned int indicies[] =
	{
		0,1,2,
		2,3,0
	};

	// Blending
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	

	VertexArray va;

	VertexBuffer vb(positions, 4 * 4 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);


	IndexBuffer ib(indicies, 6);

	// Create shader

	Shader shader("resources/shaders/Basic.shader");
	shader.Bind();
	shader.SetUniform4f("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);

	Texture texture("resources/textures/images.png");
	texture.Bind();
	shader.SetUniform1i("u_Texture", 0);


	// vv clear buffers vv
	va.Unbind();
	shader.Unbind();
	vb.Unbind();
	ib.Unbind();
	// ^^ clear buffers ^^

	Renderer renderer;
	



	float Red = 0.0f;
	float increment = 0.02f;
	while (!glfwWindowShouldClose(window))
	{
		renderer.Clear();

		// vv Re bind buffers every frame vv
		shader.Bind();
		shader.SetUniform4f("u_Color", Red, 0.0f, 1.0f, 1.0f); // set unifrom in shader 
		// ^^ Re bind buffers every frame ^^

		
		//vv Change colors vv

		if (processInput(window))
		{
		 
			if (Red > 1.0f)
				increment = -0.02f;
			else if(Red < 0.0f)
				increment = 0.02f;
			Red += increment;
		}


		
		// ^^ Change colors ^^

		//draw call
		glClearColor(1.0f, 1.0f, 1.0, 1.0f);
		renderer.Draw(va, ib, shader);

		// Swap front and back buffers
		glfwSwapBuffers(window);

		glfwPollEvents();
		processInput(window);
	}
	glfwTerminate();
	return 0;

	//	/*Application* app = new Application();
	//
	//	app->Startup();
	//
	//	delete app;*/


}
// ^^^ AIDANS CODE FOR OPEN GL SHADERS ^^^



// VVVVVVVVVVVV DEEP CODE VVVVVVVVVVVV


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

bool processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		return true;

}