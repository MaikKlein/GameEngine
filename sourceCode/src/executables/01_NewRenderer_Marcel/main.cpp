#include "Level.h"
#include "Scenegraph.h"
#include "Node.h"

int main()
{

	/*TEST AREA TEST AREA TEST AREA TEST AREA TEST AREA TEST AREA*/

	//Nur Testmethoden um die grundlegende Funktionalität zu prüfen
	Level level("TestLevel");

	Node node("TestNode");

	/*Test: Szenegraphen Methoden
	  SUCCESS*/
	Scenegraph* scene = level.getScenegraph();
	std::string* sceneName = scene->getScenegraphName();
	Node* roodNode = scene->getRootNode();
	/*ERROR:*/
	roodNode->addChildrenNode(&node);



	//Test: Modelmatrix setzen
	//SUCCESS
	node.setModelMatrix(glm::mat4(1));

	//Test: Modelmatrix zurücksetzen
	//SUCCESS
	node.setIdentityMatrix_ModelMatrix();

	/*Test: Rotation ausführen
	  SUCCESS*/
	node.addRotation(30, glm::vec3(1, 0, 0));

	/*Test: Translation ausführen
	  SUCCESS*/
	node.addTranslation(1, 2, 3);

	/*Test: Skalierung ausführen
      SUCCESS*/
	node.addScale(2, 2, 2);

	/*Test: Matrizen zurücksetzen
	  SUCCESS*/
	node.setIdentityMatrix_Rotation();
	node.setIdentityMatrix_Scale();
	node.setIdentityMatrix_Translate();

	/*Test: Getter Methoden
	SUCCESS*/
	std::string* name = node.getNodeName();
	glm::mat4 modelMatrix = node.getModelMatrix();
	glm::mat4 rotation = node.getRotationMatrix();
	glm::mat4 translation = node.getTranslationMatrix();
	glm::mat4 scale = node.getScaleMatrix();

	/*Test: Parentnode setzen und zurückholen
	SUCCESS*/
	//node.setParentNode(root);
	//Node* parent = node.getParentNode();

	/*Test: Children hinzufügen und zurückholen, löschen und komplette childrenSet-Liste löschen
	SUCCESS*/
	Node childrenOne("childrenOne");
	node.addChildrenNode(&childrenOne);
	Node* childrenOneBack = node.getChildrenNode("childrenOne");
	node.deleteChildrenNode("childrenOne");
	node.addChildrenNode(&childrenOne);
	node.clearChildrenSet();

	


	return 0;
}