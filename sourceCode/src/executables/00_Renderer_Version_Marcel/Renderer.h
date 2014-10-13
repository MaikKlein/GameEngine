/*#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_inverse.hpp>
*/
#include <iostream>
#include "Object.h"
#include "Window.h"
#include "Shader.h"

//The Renderer should initialize the window, load ressources of an Object, bind a shader and render/draw the object on the screen

class Renderer
{

public:

	//The constructor of the Renderer
	//TODO: Maybe we give the Renderer a List, the szenegraph?
	//TODO: Should the Renderer has a szenegraph as attribute?
	Renderer();
	//This constructor set a vertex and fragment Shader, initialize a window and sets the openGL-Version, it also prints the OpenGL Infos
	//The Renderer also gets an object, which he should render later
	Renderer(std::string vertexShader, std::string fragmentShader, Object* object);
	~Renderer();

/*	void loadRessources(GLfloat vertices[], int points);
*/

/*	void renderLoop(GLFWwindow* window);
*/

	//This Method starts the rendering process, a.k.a the render-loop
	void start();

	//A getter for the window
	Window* getWindow();

	//The Renderer should use only this version, for use on all devices
	//TODO:Maybe optional and changable?
	void useOpenGL33();

	//Information about the System, the renderer is running on
	//TODO: On and Off switch?
	void printInformation();

private:
	//With this method a standard window is automatically started
	void initializeWindow();
	//With this method a given shader is started, just vertex and fragment for starters
	void initializeShader(std::string vertexShader, std::string fragmentShader);
	//This method tells the object, that it should render itself, this means: load the buffers, draw on the screen
	//TODO: 2D and 3D support, maybe multiple Render-classes?
	void render(GLFWwindow* window, Object* object);

protected:
	//every renderer has a window and a shader given
	Window* m_window;
	Shader* m_shader;
	Object* m_object;
	/*int m_points;
	*/

};