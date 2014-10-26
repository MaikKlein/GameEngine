#include "Node.h"


Node::Node(const char* nodeName)
{
	m_nodeName = nodeName;
}


Node::~Node()
{
}

void Node::addChildrenNode(Node* node)
{
	m_childrenSet.push_back(node);
}