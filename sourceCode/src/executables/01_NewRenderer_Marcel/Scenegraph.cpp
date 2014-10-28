#include "Scenegraph.h"


Scenegraph::Scenegraph(std::string scenegraphName)
{
	m_scenegraphName = scenegraphName;

	Node rootNode("Root");
    setRootNode(&rootNode);
}


Scenegraph::~Scenegraph()
{
}

std::string* Scenegraph::getScenegraphName()
{
	return &m_scenegraphName;
}

Node* Scenegraph::getRootNode()
{
	return m_rootNode;
}

void Scenegraph::setRootNode(Node* rootNode)
{
	m_rootNode = rootNode;
}