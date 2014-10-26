#pragma once
#include <vector>
#include <glm/ext.hpp>

/*A "Node" should be a container for Geometry, Material, Lights and Cameras and provides all the information a shader could need
  like a Modelmatrix for example. It has one parent and can have a lot of children or none. Every Node exists as long as the scenegraph */
class Node
{
public:
	///The constructor of a Node
	/*At the beginning a Node just needs a name*/
	Node(const char* nodeName);
	~Node();

	///A getter for the name of a Node
	/*Returns the name of the Node as const char*/
	const char* getNodeName();

	///A getter for the parent of the Node
	/*Returns a Node Object which represent the Parent Node*/
	Node* getParentNode();

	///A add-Method for the list of children 
	/*A NodeObject is given by the user and the node puts the new node into his m_childrenSet as a new children*/
	void addChildrenNode(Node* childrenNode);
	
	///A delete Method to delete a child
	/*The user gives the method a name and the method iterates over the m_childrenSet and deletes the Child with the nodeName*/
	void deleteChildrenNode(const char* nodeName);

	///A method to clear the whole set of children
	/*Every Child Node in m_childrenNode will be deleted*/
	void clearChildrenSet();

	///A getter Method for a children Node
	/*This Method iterates over the m_childrenSet and returns the Node with the nodeName*/
	Node* getChildrenNode(const char* nodeName);

	///A getter Method for the Modelmatrix
	/*Returns the Modelmatrix of the current Node as a matrix*/
	glm::mat4 getModelMatrix();

	///A Setter Method for the Modelmatrix
	/*A complete mat4 Modelmatrix is given by the user and will be the m_modelMatrix of the Node*/
	void setModelMatrix(glm::mat4);

	///A rotation will be added to the Modelmatrix
	/*The user tells the method how big the angle should be and around which axis we are rotation.
	  Then the method calls the rotate(...) Method of opengl and updates the modelmatrix*/
	void addRotation(float angle, glm::vec3 axis);

	///A translation will be added to the Modelmatrix
	/*The user tells the method how far the object will move in x,y and z direction.
	Then the method calls the translate(...) Method of opengl and updates the modelmatrix*/
	void addTranslation(float x, float y, float z);

	///A scale will be added to the Modelmatrix
	/*The user tells the method in which directions (x, y and/or z) the object should be scaled.
	Then the method calls the scale(...) Method of opengl and updates the modelmatrix*/
	void addScale(float x, float y, float z);

protected:
	const char* m_nodeName;
	Node* m_parentNode;
	std::vector<Node*> m_childrenSet;

	glm::mat4 m_modelMatrix;

};

