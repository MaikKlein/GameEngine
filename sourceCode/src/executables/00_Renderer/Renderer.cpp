#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <glm/glm.hpp>

#include "Renderer.h"

/*
by initializing, the renderer check, if the OS support OpenGL
*/
Renderer::Renderer()
{
	std::cout << "Renderer was initialized" << std::endl;
	useOpenGL33CoreProfile();
	printInfo();
}

Renderer::~Renderer()
{
}

int numberOfPoints;

/*
get an object, now only vertices, and load it to the VBO & VAO
*/
void Renderer::loadObject(std::vector<glm::vec3> *m_vertices)
{

	numberOfPoints = m_vertices->size();

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertices->size() * sizeof(glm::vec3), &m_vertices->at(0), GL_STATIC_DRAW);

	GLuint vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

/*
main rendering routine
*/
void Renderer::render(GLFWwindow* window)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, numberOfPoints);
	glfwSwapBuffers(window);
	glfwPollEvents();
}

/*
check if it works well with mac, i think
*/
void Renderer::useOpenGL33CoreProfile(){
	std::cout << "Testing Compatibility " << std::endl;
#ifdef __APPLE__
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glewExperimental = GL_TRUE;
#endif
}

/*
print Information about the supported OpenGL & GLSL version, Vendor and Renderer
*/
void Renderer::printInfo(){

	std::cout << "=============================================" << std::endl;
	// print out some info about the graphics drivers
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "=============================================" << std::endl;
}