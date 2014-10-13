
#include "Renderer.h"

Renderer::Renderer()
{
	useOpenGL33();
	printInformation();
}


Renderer::~Renderer()
{

}

void Renderer::loadRessources(GLfloat vertices[], int points)
{
	m_points = points / 8;

	GLuint vertexBufferHandle;
	glGenBuffers(1, &vertexBufferHandle);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, points, vertices, GL_STATIC_DRAW);

	GLuint vertexArrayHandle;
	glGenVertexArrays(1, &vertexArrayHandle);
	glBindVertexArray(vertexArrayHandle);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
}


void Renderer::renderLoop(GLFWwindow* window)
{

	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, m_points);

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Renderer::render(GLFWwindow* window, Object* object)
{
	object->render(window);
}


void Renderer::useOpenGL33()
{
#ifdef __APPLE__
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glewExperimental = GL_TRUE;
#endif
}

void Renderer::printInformation()
{
	std::cout << "=============================================" << std::endl;
	// print out some info about the graphics drivers
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "=============================================" << std::endl;
}