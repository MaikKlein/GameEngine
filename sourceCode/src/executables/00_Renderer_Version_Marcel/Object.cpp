#include "Object.h"

Object::Object(){}

Object::~Object(){}

void Object::render(GLFWwindow* window)
{
	GLfloat vertices[] =
	{
		0.5, -0.5,
		-0.5, -0.5,
		0.5, 0.5,
		-0.5, 0.5,
	};

	createBuffer(vertices);

	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, sizeof(vertices) / 8);

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Object::createBuffer(GLfloat(&vertices)[8])
{

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);


}