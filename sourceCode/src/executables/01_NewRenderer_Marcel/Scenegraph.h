#pragma once
#include "Node.h"

/**Every scenegraph is connected with one scene.
The scenegraph is managing all the objects in the scene which are added to the scenegraph by adding them to the scene*/
class Scenegraph
{
public:
	Scenegraph();
	///A scenegraph just gets a Name
	/*The m_scenegraphName will be set and the m_rootNode will be set automatically too*/
	Scenegraph(std::string scenegraphName);
	~Scenegraph();

	///A Setter for the name of the scenegraph
	/*Sets the m_scenegraphName attribute */
	void setScenegraphName(std::string scenegraphName);

	///A getter for the Name of the scenegraph
	/*Returns a the m_scenegraphName as a string*/
	std::string* getScenegraphName();

	///A setter for the Root Node of the scenegraph
	/*The m_rootNode attribute will be set to a Node object*/
	void setRootNode(Node rootNode);

	/// A getter for the root node
	/*Returns the m_rootNode as a Node object*/
	Node* getRootNode();

protected:
	Node m_rootNode;
	std::string m_scenegraphName;
};

