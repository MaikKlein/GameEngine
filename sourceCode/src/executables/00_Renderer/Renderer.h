#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Renderer
{
public:
	Renderer();
	~Renderer();

	int numberOfPoints;
	void loadObject(GLfloat vertices[], int anzahl);
	void render(GLFWwindow* window);
	void useOpenGL33CoreProfile();
	void printInfo();
};
#endif 