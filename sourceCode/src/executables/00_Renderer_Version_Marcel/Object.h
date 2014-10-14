#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Object{

public:
	Object();
	~Object();

	void render(GLFWwindow* window);

private:
	void createBuffer(GLfloat(&vertices)[8]);
	
};