#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>

#include "Window.h"	
#include "Renderer.h"
#include "Shader.h"
//#include "Object.h"

//Example
GLfloat vertices[] =
{
	0.5, -0.5,
	-0.5, -0.5,
	0.5, 0.5,
	-0.5, 0.5,
};

//TODO: Should only be the Front-End for the user
int main(){

	//We initialize a window
	//TODO: This should do the renderer-class
	glfwInit();
	Window* window = new Window(800, 600, "Renderer");
	window->initialize();
	glewInit();


	Object* object = new Object();

	//We initialize the renderer
	Renderer* renderer = new Renderer();
	//renderer->loadRessources(vertices, sizeof(vertices));


	//We initialize the shader
	//TODO: Should happen in the renderer-class
	Shader* shader = new Shader("00_Renderer\\minimal.vert", "00_Renderer\\minimal.frag");

	while (!glfwWindowShouldClose(window->getWindow())){

		//renderer->renderLoop(window->getWindow());
		//object->render(window->getWindow());
		renderer->render(window->getWindow(), object);
		
	}
	window->destroy();

	return 0;
}