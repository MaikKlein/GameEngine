#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Object{

public:
	//Just empty constructors
	Object();
	~Object();

	//this Method tells every object to load its information into buffers and draw themselfes onto the screen
	void render(GLFWwindow* window);

private:
	//this method is called by the method render(...) and cannot be opened from outside
	void createBuffer(GLfloat(&vertices)[8]);
	
};