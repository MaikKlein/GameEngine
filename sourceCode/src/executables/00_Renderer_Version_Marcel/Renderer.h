
#include <iostream>
#include "Object.h"
#include "Window.h"
#include "Shader.h"
#include "Rect.h"

//The Renderer should initialize the window, load ressources of an Object, bind a shader and render/draw the object on the screen
class Renderer
{
public:
	//TODO: Maybe we give the Renderer a List, the szenegraph?
	//TODO: Should the Renderer has a szenegraph as attribute?
	Renderer();
	Renderer(std::string vertexShader, std::string fragmentShader, Rect* object);
	~Renderer();

	void start();

	Window* getWindow();

	//TODO:Maybe optional and changable?
	void useOpenGL33();

	//TODO: On and Off switch?
	void printInformation();

private:
	
	void initializeWindow();
	void initializeShader(std::string vertexShader, std::string fragmentShader);
	//TODO: 2D and 3D support, maybe multiple Render-classes?
	void render(GLFWwindow* window, Rect* object);

protected:

	Window* m_window;
	Shader* m_shader;
	Rect	* m_object;


};