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

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


bool processInput(GLFWwindow* window, unsigned int key);

//#include "engine/declarations/Application.h" // commented out to make compilation faster

int main()
{
	// vvv INITIALIZATION vv
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	// vv Make GL Version core instead of compat vv
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// ^^ Make GL Version core instead of compat ^^


	window = glfwCreateWindow(960, 540, "Window Title", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return - 1;
	}

	glfwMakeContextCurrent(window);

	glfwSwapInterval(1); // Syncs swap interval with vsync

	if (glewInit() != GLEW_OK)
		std::cout << "ERROR!" << std::endl;

	// Enabling Blending
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	// ^^^ INITIALIZATION ^^^

	std::cout << glGetString(GL_VERSION) << std::endl;

	// CREATING PROJECTION MATRIX
	glm::mat4 projection = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	glm::vec3 translationA(200, 200, 0);
	glm::vec3 translationB(400, 200, 0);
	glm::vec4 vp(100.0f, 100.0f, 0.0f, 1.0f);

	glm::vec4 result = projection * vp;
	
	// Create shader

	Shader shader("resources/shaders/Basic.shader");
	shader.Bind();
	shader.SetUniform4f("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);

	Texture texture("resources/textures/cherno.png");
	texture.Bind();
	shader.SetUniform1i("u_Texture", 0);

	Texture spriteTexture("resources/textures/sp.png");
	


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


	float positions[] = {
		-50.0f, -50.0f, 0.0f, 0.0f, // 0 - bottom left
		50.0f, -50.0f, 1.0f, 0.0f, // 1 - bottom right
		50.0f, 50.0f, 1.0f, 1.0f, // 2 - top right
		-50.0f, 50.0f, 0.0f, 1.0f // 3 - top left
	};

	// Vertecies of triangles
	//float positions[] = {
	//	-1.0f, -1.0f, 0.0f, 0.0f, // 0 - bottom left
	//	1.0f, -1.0f, 1.0f, 0.0f, // 1 - bottom right
	//	1.0f, 1.0f, 1.0f, 1.0f, // 2 - top right
	//	-1.0f, 1.0f, 0.0f, 1.0f // 3 - top left
	//};



	// index buff for connecting points
	unsigned int indicies[] =
	{
		0,1,2,
		2,3,0
	};
	

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

		
		

		
		//vv INPUT vv

		if (processInput(window,GLFW_KEY_W))
		{
			translationA.y++;
		}
		if (processInput(window, GLFW_KEY_A))
		{
			translationA.x--;
		}
		if (processInput(window, GLFW_KEY_S))
		{
			translationA.y--;
		}
		if (processInput(window, GLFW_KEY_D))
		{
			translationA.x++;
		}


		if (processInput(window, GLFW_KEY_UP))
		{
			translationB.y++;
		}
		if (processInput(window, GLFW_KEY_LEFT))
		{
			translationB.x--;
		}
		if (processInput(window, GLFW_KEY_DOWN))
		{
			translationB.y--;
		}
		if (processInput(window, GLFW_KEY_RIGHT))
		{
			translationB.x++;
		}
		// ^^ INPUT ^^


		

		



		// vvv FIRST OBJECT DRAW vvv
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
			glm::mat4 mvp = projection * view * model; // (Model View Projection)
			shader.Bind(); // Re bind shader every frame
			texture.Bind();
			shader.SetUniform1i("u_Texture", 0);
			shader.SetUniformMat4f("u_ModelViewProjectionMatrix", mvp);

			renderer.Draw(va, ib, shader);
		}
		// ^^^ FIRST OBJECT DRAW ^^^


		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
			glm::mat4 mvp = projection * view * model; // (Model View Projection)
			shader.Bind(); // Re bind shader every frame
			spriteTexture.Bind(); // Re bind shader every frame
			shader.SetUniform1i("u_Texture", 0);
			shader.SetUniformMat4f("u_ModelViewProjectionMatrix", mvp);
			renderer.Draw(va, ib, shader);
		}

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