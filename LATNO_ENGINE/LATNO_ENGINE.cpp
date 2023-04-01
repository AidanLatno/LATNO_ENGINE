// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#define GLEW_STATIC
#include <glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "engine/declarations/Rendering/VertexArray.h"
#include "engine/declarations/Rendering/IndexBuffer.h"
#include "engine/declarations/Rendering/VertexBufferLayout.h"
#include "engine/declarations/Rendering/Shader.h"
#include "engine/declarations/Rendering/Texture.h"


bool processInput(GLFWwindow* window, unsigned int key);

//#include "engine/declarations/Application.h" // commented out to make compilation faster

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


	window = glfwCreateWindow(1000, 1000, "Window Title", NULL, NULL);
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

	
	// Create shader

	Shader shader("resources/shaders/Basic.shader");
	shader.Bind();
	shader.SetUniform4f("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);

	Texture texture("resources/textures/cherno.png");
	texture.Bind();
	shader.SetUniform1i("u_Texture", 0);

	//float w = texture.GetWidth() * scale;
	//float h = texture.GetHeight() * scale;

	//while (w >= 10)
	//{
	//	w /= 10;
	//}
	//while (h >= 10)
	//{
	//	h /= 10;
	//}

	//// Vertecies of triangles
	//float positions[] = {
	//	-w, -h, 0.0f, 0.0f, // 0 - bottom left
	//	w, -h, 1.0f, 0.0f, // 1 - bottom right
	//	w, h, 1.0f, 1.0f, // 2 - top right
	//	-w, h, 0.0f, 1.0f // 3 - top left
	//};


	// Vertecies of triangles
	float positions[] = {
		-1.0f, -1.0f, 0.0f, 0.0f, // 0 - bottom left
		1.0f, -1.0f, 1.0f, 0.0f, // 1 - bottom right
		1.0f, 1.0f, 1.0f, 1.0f, // 2 - top right
		-1.0f, 1.0f, 0.0f, 1.0f // 3 - top left
	};

	// index buff for connecting points
	unsigned int indicies[] =
	{
		0,1,2,
		2,3,0
	};

	// Blending -- Ignore for now
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	

	VertexArray va;

	VertexBuffer vb(positions, 4 * 4 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indicies, 6);

	// vv clear buffers vv
	va.Unbind();
	shader.Unbind();
	vb.Unbind();
	ib.Unbind();
	// ^^ clear buffers ^^

	Renderer renderer;
	

	float Red = 0.0f;
	float increment = 0.02f;


	glClearColor(1.0f, 1.0f, 1.0, 1.0f); // Set background white

	while (!glfwWindowShouldClose(window))
	{
		renderer.Clear(); // clear renderer (glClear(GL_COLOR_BUFFER_BIT);)

		
		shader.Bind(); // Re bind shader every frame
		shader.SetUniform4f("u_Color", Red, 0.0f, 1.0f, 1.0f); // set unifrom for color in shader 
		// ^^ Re bind buffers every frame ^^

		
		//vv Change colors vv

		if (processInput(window,GLFW_KEY_SPACE))
		{
			if (Red > 1.0f)
				increment = -0.02f;
			else if(Red < 0.0f)
				increment = 0.02f;
			Red += increment;
		}


		
		// ^^ Change colors ^^

		//draw call
		renderer.Draw(va, ib, shader);

		// Swap front and back buffers
		glfwSwapBuffers(window);

		glfwPollEvents(); // idk man
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

bool processInput(GLFWwindow* window,unsigned int key) {
	if (glfwGetKey(window, key) == GLFW_PRESS)
		return true;
	return false;
}