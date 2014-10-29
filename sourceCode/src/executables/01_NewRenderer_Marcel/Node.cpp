#include "Node.h"

Node::Node()
{
	m_nodeName = "Default";

	setIdentityMatrix_ModelMatrix();
}

Node::Node(std::string nodeName)
{
	m_nodeName = nodeName;

	setIdentityMatrix_ModelMatrix();
}


Node::~Node()
{
}

std::string* Node::getNodeName()
{
	return &m_nodeName;
}

void Node::setNodeName(std::string nodeName)
{
	m_nodeName = nodeName;
}

Node* Node::getParentNode()
{
	return m_parentNode;
}

void Node::setParentNode(Node* parentNode)
{
	m_parentNode = parentNode;
}

void Node::addChildrenNode(Node* node)
{
	//Darf man hier move benutzen??
//	m_childrenSet.push_back(std::move(node));
	m_childrenSet.push_back(node);

	node->setParentNode(this);
}

void Node::deleteChildrenNode(std::string nodeName)
{
	for (int i = 0; i < m_childrenSet.size(); i++)
	{
		//TODO: bessere vergleichsmethode von const char??
		if (m_childrenSet.at(i)->getNodeName()->compare(nodeName))
		{
			m_childrenSet.erase(m_childrenSet.begin()+i);
		}
	}
}

void Node::clearChildrenSet()
{
	m_childrenSet.clear();
}

Node* Node::getChildrenNode(std::string nodeName)
{
	
	for (int i = 0; i < m_childrenSet.size(); i++)
	{

		if (m_childrenSet.at(i)->getNodeName()->compare(nodeName))
		{
			return m_childrenSet.at(i);
		}
	}

	//TODO: Sollte was bessers als "NULL" zurückgeben
	return NULL;
}

glm::mat4 Node::getModelMatrix()
{
	return m_modelMatrix;
}

void Node::setModelMatrix(glm::mat4 modelMatrix)
{
	m_modelMatrix = modelMatrix;
}


void Node::addRotation(float angle, glm::vec3 axis)
{
	glm::mat4 newRotationMatrix = glm::rotate(getRotationMatrix(), angle, axis);
	m_rotationMatrix = newRotationMatrix;

	updateModelMatrix(m_rotationMatrix);
}

glm::mat4 Node::getRotationMatrix()
{
	return m_rotationMatrix;
}

void Node::addTranslation(float x, float y, float z)
{
	glm::vec3 transfer = glm::vec3(x, y, z);
	glm::mat4 newTranslationMatrix = glm::translate(getTranslationMatrix(), transfer);
	m_translateMatrix = newTranslationMatrix;

	updateModelMatrix(m_translateMatrix);
}

glm::mat4 Node::getTranslationMatrix()
{
	return m_translateMatrix;
}

void Node::addScale(float x, float y, float z)
{
	glm::vec3 scale = glm::vec3(x, y, z);
	glm::mat4 newScaleMatrix = glm::scale(getScaleMatrix(), scale);
	m_scaleMatrix = newScaleMatrix;

	updateModelMatrix(m_scaleMatrix);
}

glm::mat4 Node::getScaleMatrix()
{
	return m_scaleMatrix;
}

void Node::updateModelMatrix(glm::mat4 updateMatrix)
{
	m_modelMatrix = updateMatrix * m_modelMatrix;
}

void Node::setIdentityMatrix_Translate()
{
	glm::mat4 inverseMatrix = glm::inverse(m_translateMatrix);
	m_modelMatrix = inverseMatrix * m_modelMatrix;
	m_translateMatrix = inverseMatrix * m_translateMatrix;
}

void Node::setIdentityMatrix_Scale()
{
	glm::mat4 inverseMatrix = glm::inverse(m_scaleMatrix);
	m_modelMatrix = inverseMatrix * m_modelMatrix;
	m_scaleMatrix = inverseMatrix * m_scaleMatrix;
}

void Node::setIdentityMatrix_Rotation()
{
	glm::mat4 inverseMatrix = glm::inverse(m_rotationMatrix);
	m_modelMatrix = inverseMatrix * m_modelMatrix;
	m_rotationMatrix = inverseMatrix * m_rotationMatrix;
}

void Node::setIdentityMatrix_ModelMatrix()
{
	m_modelMatrix = glm::mat4(1);
}

void Node::addGeometry(Geometry* geometry)
{
	m_geometry = geometry;
}

Geometry* Node::getGeometry()
{
	return m_geometry;
}
