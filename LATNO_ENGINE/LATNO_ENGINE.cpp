// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifdef GLEW_STATIC
#  define GLEWAPI extern
#else
#  ifdef GLEW_BUILD
#    define GLEWAPI extern __declspec(dllexport)
#  else
#    define GLEWAPI extern __declspec(dllimport)
#  endif
#endif


#include <glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void render(GLFWwindow* window) {

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput (GLFWwindow *window){
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);






	GLFWwindow* window = glfwCreateWindow(800, 600, "learnopengl", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "failed to create glfw window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		
		render(window);

		glfwSwapBuffers(window);
		glfwPollEvents();
		

	}

	glfwTerminate();
		
	return 0;
}


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