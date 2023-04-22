// LATNO_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "engine/declarations/Application.h" // commented out to make compilation faster

bool processInput(GLFWwindow* window, unsigned int key);



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


	window = glfwCreateWindow(864, 988, "Window Title", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

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

	Application* app = new Application();
	app->Startup(window);
	
	//while (!glfwwindowshouldclose(window))
	//{
	//	imgui_implglfwgl3_newframe();
	//	app->tick();

	//	imgui::render();
	//	imgui_implglfwgl3_renderdrawdata(imgui::getdrawdata());

	//	glfwswapbuffers(window);

	//	glfwpollevents(); // idk man
	//}
	delete app;

	return 0;
}

bool processInput(GLFWwindow* window, unsigned int key) {
	if (glfwGetKey(window, key) == GLFW_PRESS)
		return true;
	return false;
}