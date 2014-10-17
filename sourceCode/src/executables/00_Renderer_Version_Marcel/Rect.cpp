#include "Rect.h"

Rect::Rect()
{
	m_vertices.push_back(glm::vec3(0.5, -0.5, 0.0));
	m_vertices.push_back(glm::vec3(-0.5, -0.5, 0.0));
	m_vertices.push_back(glm::vec3(0.5, 0.5, 0.0));
	m_vertices.push_back(glm::vec3(-0.5, 0.5, 0.0));

}
Rect::~Rect(){}

void Rect::createBuffer()
{
	
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size()*sizeof(glm::vec3), &m_vertices[0], GL_STATIC_DRAW);

	GLuint vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	
}

void Rect::render(GLFWwindow* window)
{
	
//	this->createBuffer();
	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glfwSwapBuffers(window);
	glfwPollEvents();
}