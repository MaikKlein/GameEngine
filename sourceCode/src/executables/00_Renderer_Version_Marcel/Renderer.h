#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include "Object.h"

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

/*	void loadRessources(GLfloat vertices[], int points);
*/

/*	void renderLoop(GLFWwindow* window);
*/

	//This method tells the object, that it should render itself, this means: load the buffers, drawing on the screen
	//TODO: 2D and 3D support, maybe multiple Render-classes?
	void render(GLFWwindow* window, Object* object);

	

	//The Renderer should use only this version, for use on all devices
	//TODO:Maybe optional and changable?
	void useOpenGL33();

	//Information about the System, the renderer is running on
	//TODO: On and Off switch?
	void printInformation();

private:
	
	/*int m_points;
	*/

};