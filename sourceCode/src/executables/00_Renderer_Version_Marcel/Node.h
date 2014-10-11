#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_inverse.hpp>

//A node represents an object an is used for a scenegraph
class Node
{
public:
	//The constructor just need a name
	Node();
	Node(const char* name);
	~Node();

	//Every Node is represented by its name
	void setName(const char* name);
	const char* getName();

	//every node is an object so it needs a modelMatrix
	//TODO: we have to think about the accumulation
	void setModelMatrix(glm::mat4 modelMatrix);
	glm::mat4 getModelMatrix();

	//every Node has one parent
	void setParent(Node* parent);
	Node* getParent();
	void removeParent();

	//every node can has 0...n childs
	//TODO: every child needs the modelMatrix of its parent
	void addChild(Node* child);
	std::vector<Node*> getChild();
	void removeChild(Node* child);

	//TODO: every Node has a material, for starters just a color
	void setColor(int r, int g, int b);
	
	//TODO: Every node has a geometry from an object
	//void setObject(Object* geometry);
	//Object* getObject();

	//This method uses the Object-class and starts de buffer-loading
	//TODO: Object-class
	void startRender();
private:
	const char* m_name;
	glm::mat4 m_modelMatrix;
	std::vector<Node*> m_childNodes;
	Node* parentNode;

	//colorMaterial* color;
	//Object* geometry;

};