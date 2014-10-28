#ifndef RENDERER_H
#define RENDERER_H

#include "DefinitionAndInclude.h"

/*
Need Information
*/
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