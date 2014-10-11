#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


//The Renderer should initialize the window, load ressources of an Object, bind a shader and render/draw the object on the screen

class Renderer
{

public:

	//The constructor of the Renderer
	//TODO: Maybe we give the Renderer a List, the szenegraph?
	//TODO: Should the Renderer has a szenegraph as attribute?
	//TODO: Should the Renderer initialize the Window at this point?
	Renderer();
	~Renderer();

	//The Renderer gets data and should store them in Buffers with this method
	//TODO: Until now just vertices, no really Objects
	//TODO: 2D and 3D support, maybe multiple Render-classes?
	void loadRessources(GLfloat vertices[]);

	//The Render-Loop needs to clear and swap the buffers, this method draws the objects too
	void renderLoop(GLFWwindow* window);

	//The Renderer should use only this version, for use on all devices
	//TODO:Maybe optional and changable?
	void useOpenGL33();

	//Information about the System, the renderer is running on
	//TODO: On and Off switch?
	void printInformation();

};