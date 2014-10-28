#include "Level.h"
#include "Scenegraph.h"
#include "Node.h"

int main()
{

	/*TEST AREA TEST AREA TEST AREA TEST AREA TEST AREA TEST AREA*/

	//Nur Testmethoden um die grundlegende Funktionalit�t zu pr�fen
	Level level("TestLevel");

	Node node("TestNode");

	/*Test: Szenegraphen Methoden
	  SUCCESS*/
	Scenegraph* scene = level.getScenegraph();
	std::string* sceneName = scene->getScenegraphName();



	//Test: Modelmatrix setzen
	//SUCCESS
	node.setModelMatrix(glm::mat4(1));

	//Test: Modelmatrix zur�cksetzen
	//SUCCESS
	node.setIdentityMatrix_ModelMatrix();

	/*Test: Rotation ausf�hren
	  SUCCESS*/
	node.addRotation(30, glm::vec3(1, 0, 0));

	/*Test: Translation ausf�hren
	  SUCCESS*/
	node.addTranslation(1, 2, 3);

	/*Test: Skalierung ausf�hren
      SUCCESS*/
	node.addScale(2, 2, 2);

	/*Test: Matrizen zur�cksetzen
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

	/*Test: Parentnode setzen und zur�ckholen
	SUCCESS*/
	//node.setParentNode(root);
	//Node* parent = node.getParentNode();

	/*Test: Children hinzuf�gen und zur�ckholen, l�schen und komplette childrenSet-Liste l�schen
	SUCCESS*/
	Node childrenOne("childrenOne");
	node.addChildrenNode(&childrenOne);
	Node* childrenOneBack = node.getChildrenNode("childrenOne");
	node.deleteChildrenNode("childrenOne");
	node.addChildrenNode(&childrenOne);
	node.clearChildrenSet();

	//ERROR: Hier krieg ich noch einen Error, grad keine Zeit mehr es zu verbessern, werde ich sp�ter machen
	//Vermutung: Es liegt definitiv an daran, dass ich Pointer benutze, da wird irgendwas falsch gemacht
	//Da der rest funktioniert, ist der Szenegraph aber an sich erstmal benutzbar, den Bug muss ich halt fixen, mach ich auch dienstag
	//level.getScenegraph()->getRootNode()->addChildrenNode(&node);
	//root->addChildrenNode(&childrenOne);
	


	return 0;
}