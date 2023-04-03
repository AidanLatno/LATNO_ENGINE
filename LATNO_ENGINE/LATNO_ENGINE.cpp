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
#include "engine/declarations/Rendering/Sprite.h"


#include "engine/declarations/Rendering/Tests/Test.h"
#include "engine/declarations/Rendering/Tests/TestClearColor.h"
#include "engine/declarations/Rendering/Tests/TestTexture.h"
#include "engine//declarations/Rendering/Tests/TestDVD.h"


#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "vendor/ImGui/imgui_impl_glfw_gl3.h"
#include "vendor/ImGui/imgui.h"

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

	std::cout << glGetString(GL_VERSION) << std::endl;

	// CREATING PROJECTION MATRIX
	glm::mat4 projection = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	glm::vec3 translationA(200, 200, 0);
	glm::vec3 translationB(400, 200, 0);

	// Create shader

	Shader shader("resources/shaders/Basic.shader");
	shader.Bind();
	shader.SetUniform4f("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);

	Texture texture("resources/textures/cherno.png");
	texture.Bind();
	shader.SetUniform1i("u_Texture", 0);

	Texture spriteTexture("resources/textures/sp.png");

	float positions[] = {
		-50.0f, -50.0f, 0.0f, 0.0f, // 0 - bottom left
		50.0f, -50.0f, 1.0f, 0.0f, // 1 - bottom right
		50.0f, 50.0f, 1.0f, 1.0f, // 2 - top right
		-50.0f, 50.0f, 0.0f, 1.0f // 3 - top left
	};

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

	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(window, true);
	ImGui::StyleColorsDark();





	test::Test* currentTest = nullptr;
	test::TestClearColor test;
	test::TestDVD dvdTest;
	test::TestMenu* testMenu = new test::TestMenu(currentTest);
	currentTest = testMenu;

	testMenu->RegisterTest<test::TestClearColor>("Clear Color");
	testMenu->RegisterTest<test::TestTexture>("Texture");
	testMenu->RegisterTest<test::TestDVD>("dvdTest");

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.0f, 1.0f, 1.0, 1.0f); // Set background white
		renderer.Clear(); // clear renderer (glClear(GL_COLOR_BUFFER_BIT);)

		ImGui_ImplGlfwGL3_NewFrame();
		if (currentTest)
		{
			currentTest->OnUpdate(ImGui::GetIO().Framerate);
			currentTest->OnRender();
			ImGui::Begin("Test");
			if (currentTest != testMenu && ImGui::Button("<-"))
			{
				delete currentTest;
				currentTest = testMenu;
			}
			currentTest->OnImGuiRender();
			ImGui::End();

		}
		//test.OnImGuiRender();
		//
		////vv INPUT vv

		//if (processInput(window,GLFW_KEY_W))
		//{
		//	translationA.y++;
		//}
		//if (processInput(window, GLFW_KEY_A))
		//{
		//	translationA.x--;
		//}
		//if (processInput(window, GLFW_KEY_S))
		//{
		//	translationA.y--;
		//}
		//if (processInput(window, GLFW_KEY_D))
		//{
		//	translationA.x++;
		//}


		//if (processInput(window, GLFW_KEY_UP))
		//{
		//	translationB.y++;
		//}
		//if (processInput(window, GLFW_KEY_LEFT))
		//{
		//	translationB.x--;
		//}
		//if (processInput(window, GLFW_KEY_DOWN))
		//{
		//	translationB.y--;
		//}
		//if (processInput(window, GLFW_KEY_RIGHT))
		//{
		//	translationB.x++;
		//}
		//// ^^ INPUT ^^








		//// vvv FIRST OBJECT DRAW vvv
		//{
		//	glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
		//	glm::mat4 mvp = projection * view * model; // (Model View Projection)
		//	shader.Bind(); // Re bind shader every frame
		//	texture.Bind();
		//	shader.SetUniform1i("u_Texture", 0);
		//	shader.SetUniformMat4f("u_ModelViewProjectionMatrix", mvp);

		//	renderer.Draw(va, ib, shader);
		//}
		//// ^^^ FIRST OBJECT DRAW ^^^

		// vvv TESTING SPRITE RENDERER vvv

	

		//{
		//	glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
		//	glm::mat4 mvp = projection * view * model; // (Model View Projection)
		//	shader.Bind(); // Re bind shader every frame
		//	spriteTexture.Bind(); // Re bind shader every frame
		//	shader.SetUniform1i("u_Texture", 0);
		//	shader.SetUniformMat4f("u_ModelViewProjectionMatrix", mvp);
		//	renderer.Draw(va, ib, shader);
		//}


		//{
		//	ImGui::SliderFloat2("float", &translationA.x, 0.0f, 960.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
		//	ImGui::SliderFloat2("float", &translationB.x, 0.0f, 960.0f);
		//	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		//}

		//rendererer->DrawSprite(spriteTexture, glm::vec2(200.0f, 200.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));


		// vvv TESTING SPRITE RENDERER vvv

		/*Sprite* rendererer;
		rendererer = new Sprite(shader);

		rendererer->DrawSprite(spriteTexture, glm::vec2(200.0f, 200.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));*/


		ImGui::Render();
		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());


		// Swap front and back buffers
		glfwSwapBuffers(window);

		glfwPollEvents(); // idk man
	}

	delete currentTest;
	if (currentTest != testMenu)
		delete testMenu;

	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();

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

bool processInput(GLFWwindow* window, unsigned int key) {
	if (glfwGetKey(window, key) == GLFW_PRESS)
		return true;
	return false;
}