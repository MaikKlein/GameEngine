#include "Level.h"
#include "Scenegraph.h"
#include "Node.h"

int main()
{

	//Nur Testmethoden um die grundlegende Funktionalit�t zu pr�fen
	Level level("TestLevel");

	Node node("TestNode");

	Node* root = level.getScenegraph()->getRootNode();
	Scenegraph* scene = level.getScenegraph();

	//ERROR: Hier krieg ich noch einen Error, grad keine Zeit mehr es zu verbessern, werde ich sp�ter machen
	//level.getScenegraph()->getRootNode()->addChildrenNode(&node);

	return 0;
}