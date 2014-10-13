#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>

#include "Window.h"	
#include "Renderer.h"
#include "Shader.h"



//TODO: Should only be the Front-End for the user
int main(){

	//We initialize a window
	//TODO: This should do the renderer-class
	glfwInit();
	Window* window = new Window(800, 600, "Renderer");
	window->initialize();
	glewInit();

	//TODO: Maybe we could have more classes of objects (triangle, rectangle etc.)
	//TODO: A better object oriented way would be nice
	Object* object = new Object();

	//We initialize the renderer
	Renderer* renderer = new Renderer();

	//We initialize the shader
	//TODO: Should happen in the renderer-class
	Shader* shader = new Shader("00_Renderer\\minimal.vert", "00_Renderer\\minimal.frag");

	while (!glfwWindowShouldClose(window->getWindow())){

		renderer->render(window->getWindow(), object);
		
	}
	window->destroy();

	return 0;
}