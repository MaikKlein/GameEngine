#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>



#include "Window.h"	
int main(){

	glfwInit();
	Window* window = new Window(800, 600, "Renderer");
	window->initialize();
	glewInit();

	while (!glfwWindowShouldClose(window->getWindow())){


	}
	window->destroy();

	return 0;
}