#pragma once
#include "Node.h"

/**Every scenegraph is connected with one level.
The scenegraph is managing all the objects in the level which are added to the scenegraph by adding them to the level*/
class Scenegraph
{
public:
	///The constructor of the scenegraph
	/**At the beginning the scenegraph just needs a name, which is given by the level. 
		Also the constructor adds a first Node-Object which will be used as the root-Node from now on*/
	Scenegraph(const char* scenegraphName);
	~Scenegraph();

	///A getter for the Name of the Scenegraph
	/**Returns the name of the scenegraph as a const char*/
	const char* getScenegraphName();

	///A getter for the Root Node
	/**Returns the m_rootNode Node-object of the scenegraph*/
	Node* getRootNode();

protected:
	const char* m_scenegraphName;
	Node* m_rootNode;

private: 
	///A setter for the Root-Node
	/**This method will be used by the constructor to create a Node-Object with the Name "Root" and add it to itself as m_rootNode*/
	void setRootNode(Node* root);
};

