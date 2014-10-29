#pragma once
#include <vector>
#include <glm/ext.hpp>
#include "Geometry.h"
#include "Rect.h"

/*A "Node" should be a container for Geometry, Material, Lights and Cameras and provides all the information a shader could need
  like a Modelmatrix for example. It has one parent and can have a lot of children or none. Every Node exists as long as the scenegraph */
class Node
{
public:
	Node();
	///The constructor of a Node
	/*At the beginning a Node just needs a name, the m_modelMatrix will be set to the identity matrix*/
	Node(std::string nodeName);
	~Node();

	///A getter for the name of a Node
	/*Returns the name of the Node as const char*/
	std::string* getNodeName();

	///A Setter for the name of the Node
	/*The m_nodeName will be set*/
	void setNodeName(std::string nodeName);

	///A getter for the parent of the Node
	/*Returns a Node Object which represent the Parent Node*/
	Node* getParentNode();

	///A setter for the parent of the Node
	/*The methods expect a node which will be used as m_parentNode*/
	void setParentNode(Node* parentNode);

	///A add-Method for the list of children 
	/*A NodeObject is given by the user and the node puts the new node into his m_childrenSet as a new children
	  The childrenNode m_parentNode will be set automatically*/
	void addChildrenNode(Node* childrenNode);
	
	///A delete Method to delete a child
	/*The user gives the method a name and the method iterates over the m_childrenSet and deletes the Child with the nodeName*/
	void deleteChildrenNode(std::string nodeName);

	///A method to clear the whole set of children
	/*Every Child Node in m_childrenNode will be deleted*/
	void clearChildrenSet();

	///A getter Method for a children Node
	/*This Method iterates over the m_childrenSet and returns the Node with the nodeName*/
	Node* getChildrenNode(std::string nodeName);

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

	///A getter for the rotationmatrix of the Node
	/*Returns the Rotationmatrix m_rotationMatrix as a mat4*/
	glm::mat4 getRotationMatrix();

	///A translation will be added to the Modelmatrix
	/*The user tells the method how far the object will move in x,y and z direction.
	Then the method calls the translate(...) Method of opengl and updates the modelmatrix*/
	void addTranslation(float x, float y, float z);

	///A getter for the translationmatrix of the Node
	/*Returns the Translationmatrix m_translateMatrix as a mat4*/
	glm::mat4 getTranslationMatrix();

	///A scale will be added to the Modelmatrix
	/*The user tells the method in which directions (x, y and/or z) the object should be scaled.
	Then the method calls the scale(...) Method of opengl and updates the modelmatrix*/
	void addScale(float x, float y, float z);

	///A Getter for the Scalematrix of the Node
	/*Returns the Scalematrix m_scaleMatrix as a mat4*/
	glm::mat4 getScaleMatrix();


	//TODO: Weiß nicht, ob das inverse für die skalierung und die Rotationsmatrix richtig sind
	//TODO: In CG1 gab es da eigene Inverse Matrizen für Rotation und Skalierung
	//TODO: Wäre auszuprobieren und eventuell anzupassen
	///The Translationmatrix will be set to the Identity matrix
	/*The Translationsmatrix will be replaced and the Modelmatrix will be updated using the inverse of the actual m_translateMatrix*/
	void setIdentityMatrix_Translate();

	///The Scalematrix will be set to the Identity matrix
	/*The Scalematrix will be replaced and the Modelmatrix will be updated using the inverse of the actual m_scaleMatrix*/
	void setIdentityMatrix_Scale();

	///The Rotationmatrix will be set to the Identity matrix
	/*The Rotationmatrix will be replaced and the Modelmatrix will be updated using the inverse of the actual m_rotateMatrix*/
	void setIdentityMatrix_Rotation();

	///The Modelmatrix will be set to the Identity matrix
	/*The Modelmatrix m_modelMatrix will be set to the identity matrix, all scales, rotations and translation will be lost*/
	void setIdentityMatrix_ModelMatrix();

	///We link a Geometry to the node
	/*A geometry Object will be linked with the node and will be saved as m_geometry*/
	void addGeometry(Geometry* geometry);

	///A Getter for the Geometry of the Node
	/*Returns m_geometry as a Geometry object*/
	Geometry* getGeometry();

	//TODO: Folgende methoden müssten noch hinzugefügt werdenlaut UML-Diagramm (werde ich teilweise am Dienstag zwischen 12 und 18 Uhr dann machen, muss morgen früh raus!)
	/*
	void addCamera(Camera* camera);
	void addLight(Light* light);
	void setMaterial(Material* material);
	*/

protected:
	std::string m_nodeName;
	Node* m_parentNode;
	std::vector<Node*> m_childrenSet;

	glm::mat4 m_modelMatrix;
	
	glm::mat4 m_rotationMatrix;
	glm::mat4 m_scaleMatrix;
	glm::mat4 m_translateMatrix;

	Geometry* m_geometry;

private:
	///A method which updates the Modelmatrix
	/*When a new rotation, scale or translation is added to the object, then the modelMatrix needs an update.
	  This update will be done by this method, the matrix which will be added to the modelMatrix is the updatedMatrix*/
	void updateModelMatrix(glm::mat4 updateMatrix);

};

