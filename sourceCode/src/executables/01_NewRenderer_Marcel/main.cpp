#include "Scenegraph.h"
#include "Node.h"
#include "Scene.h"
#include "Rect.h"
#include "Window.h"
#include "Shader.h"
#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>

int main()
{
	//*TEST AREA 1 TEST AREA 1 TEST AREA 1 TEST AREA 1 TEST AREA 1 TEST AREA 1*/

	////Nur Testmethoden um die grundlegende Funktionalität zu prüfen
	////Level level("TestLevel");

	//Node node("TestNode");

	///*Test: Szenegraphen Methoden
	//  SUCCESS*/
	//Scenegraph* scenegraph = new Scenegraph();
	//scenegraph->getRootNode();
	//Node* sceneNode = new Node();
	//scenegraph->getRootNode()->addChildrenNode(sceneNode);
	//
	///*Test: Scene  Methoden
	//  SUCCESS*/
	//Scene* scene = new Scene();
	//std::string* sceneName = scene->getSceneName();
	//scene->getScenegraph();
	//scene->setSceneName("Hallo");
	//scene->getScenegraph()->getRootNode()->addChildrenNode(sceneNode);
	//scene->getScenegraph()->getRootNode()->getChildrenNode("sceneNode");

	////Test: Modelmatrix setzen
	////SUCCESS
	//node.setModelMatrix(glm::mat4(1));

	////Test: Modelmatrix zurücksetzen
	////SUCCESS
	//node.setIdentityMatrix_ModelMatrix();

	///*Test: Rotation ausführen
	//  SUCCESS*/
	//node.addRotation(30, glm::vec3(1, 0, 0));

	///*Test: Translation ausführen
	//  SUCCESS*/
	//node.addTranslation(1, 2, 3);

	///*Test: Skalierung ausführen
 //     SUCCESS*/
	//node.addScale(2, 2, 2);

	///*Test: Matrizen zurücksetzen
	//  SUCCESS*/
	//node.setIdentityMatrix_Rotation();
	//node.setIdentityMatrix_Scale();
	//node.setIdentityMatrix_Translate();

	///*Test: Getter Methoden
	//SUCCESS*/
	//std::string* name = node.getNodeName();
	//glm::mat4 modelMatrix = node.getModelMatrix();
	//glm::mat4 rotation = node.getRotationMatrix();
	//glm::mat4 translation = node.getTranslationMatrix();
	//glm::mat4 scale = node.getScaleMatrix();

	///*Test: Parentnode setzen und zurückholen
	//SUCCESS*/
	////node.setParentNode(root);
	////Node* parent = node.getParentNode();

	///*Test: Children hinzufügen und zurückholen, löschen und komplette childrenSet-Liste löschen
	//SUCCESS*/
	//Node childrenOne("childrenOne");
	//node.addChildrenNode(&childrenOne);
	//Node* childrenOneBack = node.getChildrenNode("childrenOne");
	//node.deleteChildrenNode("childrenOne");
	//node.addChildrenNode(&childrenOne);
	//node.clearChildrenSet();

	///*Test:Rec Klasse testen in Verbindung mit dem Node
	//  SUCCESS*/
	//Rect* rec = new Rect();
	//node.addGeometry(rec);
	//node.getGeometry();

	//*TEST AREA 2 TEST AREA 2 TEST AREA 2 TEST AREA 2 TEST AREA 2 TEST AREA 2*/

	/*Test: Fenster erstellen
	  SUCCESS*/
	glfwInit();
	Window* window = new Window(100, 100, 800, 600, "Testarea");
	glewInit();
	
	/*Test: Shader binden und laden (Kevins Version)
	  SUCCESS*/
	Shader* redShader = new Shader("\\RedShader\\redShader.vert", ""/*geom*/, "" /*tessC*/, ""/*tessE*/, "\\RedShader\\redShader.frag", ""/*com*/);

	/*Test: Ein Szenegraph mit einem Rootnode und einem Node, der eine Geometrie hat
			Die Bufferdaten werden von der Geometrie gerendert
			Eine While-Schleife wird benutzt um die Geometrie zu rendern
	  SUCCESS*/
	Rect* rectangle = new Rect();
	Scene* testScene = new Scene("Testscene");
	Node* testNode = new Node("testNode");
	testNode->addGeometry(rectangle);
	testNode->getGeometry();

	testScene->getScenegraph()->getRootNode()->addChildrenNode(testNode);
	testScene->getScenegraph()->getRootNode()->getChildrenNode("testNode");
	//ERROR: Dieser Aufruf scheitert, muss aber für eine Iteration über den Szenegraphen funktionieren!!
	// Das Problem ist, dass wir das Objekt aus einer Liste holen und dann versuchen die geomterie zu holen
	/*Node* testNode2 = std::move(testScene->getScenegraph()->getRootNode()->getChildrenNode("testNode"));
	testNode2->getGeometry();*/

	testNode->getGeometry()->loadBufferData();
	while (!glfwWindowShouldClose(window->getWindow()))
	{

		testNode->getGeometry()->renderGeometry();

		glfwSwapBuffers(window->getWindow());
		glfwPollEvents();
	}

	

	return 0;
}