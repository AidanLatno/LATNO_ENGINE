// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "engine/declarations/Application.h" // commented out to make compilation faster

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


	window = glfwCreateWindow(WINDOW_LENGTH, WINDOW_HEIGHT, "LATNO ENGINE", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwSetWindowSizeLimits(window, WINDOW_LENGTH, WINDOW_HEIGHT, WINDOW_LENGTH, WINDOW_HEIGHT);
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1); // Syncs swap interval with vsync

	if (glewInit() != GLEW_OK)
		std::cout << "ERROR!" << std::endl;

	// Enabling Blending
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	// ^^^ INITIALIZATION ^^^


	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(window, true);
	ImGui::StyleColorsDark();

	Latno::Application* app = new Latno::Application();
	app->Startup(window);
	
	
	delete app;

	return 0;
}