#pragma once
#include <glm/glm.hpp>
#include<vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*This class should be used as a interface class. It provides two Methods to load Data and to render the Vertice Data. 
  Every Geometry Object which will inherit this class should use this methods. A vector for the vertices is provided as well.*/
class Geometry
{
public:
	///A standard constructor
	/*Nothing special to say about it*/
	Geometry();
	~Geometry();

	///A Method to load Buffer
	/*The vertices Data from m_vertices will be loaded into Buffers, so the Shader can use this information for the position of the object*/
	virtual void loadBufferData();

	///A method to render the Object 
	/*In the while-Loop of the main-programm (Renderer or else) this method will be called to draw the array6a6*/
	virtual void renderGeometry();

protected:
	std::vector<glm::vec3> m_vertices;

};