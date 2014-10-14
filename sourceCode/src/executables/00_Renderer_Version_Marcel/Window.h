#include <GL/glew.h>
#include <GLFW/glfw3.h>

//The Window-Class should intialize and destory a window with GLFW
//TODO: Maybe we can use different window-classes for different cases, Are there different types of windows?
class Window
{
public:
	Window();
	Window(int width, int height, const char* name);
	~Window();

	int getWidth();
	int getHeight();

	void setWidth(int width);
	void setHeight(int height);

	void setName(const char* name);
	const char* getName();

	void initialize();

	GLFWwindow* getWindow();

	void destroy();
	
private:
	int m_width, m_height;
	const char* m_name;

	GLFWwindow* m_window;

};