#include "Scenegraph.h"

Scenegraph::Scenegraph()
{
	Node root("Root");
	setRootNode(root);
}

Scenegraph::Scenegraph(std::string scenegraphName)
{
	m_scenegraphName = scenegraphName;

	Node root("Root");
	setRootNode(root);
}

Scenegraph::~Scenegraph()
{

}

std::string* Scenegraph::getScenegraphName()
{
	return &m_scenegraphName;
}

void Scenegraph::setScenegraphName(std::string scenegraphName)
{
	m_scenegraphName = scenegraphName;
}

Node* Scenegraph::getRootNode()
{
	return &m_rootNode;
}

void Scenegraph::setRootNode(Node rootNode)
{
	m_rootNode = rootNode;
}