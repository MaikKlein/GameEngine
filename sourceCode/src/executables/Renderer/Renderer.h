#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <glm/glm.hpp>

class Renderer
{
public:
	Renderer();
	~Renderer();

	int numberOfPoints;
	void loadObject(std::vector<glm::vec3> *m_vertices);
	void render(GLFWwindow* window);
	void useOpenGL33CoreProfile();
	void printInfo();
};
#endif 