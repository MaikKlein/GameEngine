
#include "Renderer.h"

Renderer::Renderer()
{
	glClearColor(1, 1, 1, 1);
	useOpenGL33();
}
Renderer::~Renderer()
{

}

void Renderer::loadRessources(GLfloat vertices[])
{

	GLuint vertexArrayHandle;
	glGenVertexArrays(1, &vertexArrayHandle);
	glBindVertexArray(vertexArrayHandle);
	glEnableVertexAttribArray(0);

	GLuint vertexBufferHandles[1];
	glGenBuffers(1, vertexBufferHandles);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandles[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

void Renderer::renderLoop(GLFWwindow* window)
{

	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glfwSwapBuffers(window);
	glfwPollEvents();
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