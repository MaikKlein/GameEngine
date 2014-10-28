#pragma once
#include "Node.h"

/**Every scenegraph is connected with one level.
The scenegraph is managing all the objects in the level which are added to the scenegraph by adding them to the level*/
class Scenegraph
{
public:
	Scenegraph();
	Scenegraph(std::string scenegraphName);
	~Scenegraph();

	void setScenegraphName(std::string scenegraphName);
	std::string* getScenegraphName();

	void setRootNode(Node rootNode);
	Node* getRootNode();

private:
	Node m_rootNode;
	std::string m_scenegraphName;
};

