#include <GL/glew.h>
#include <GLFW/glfw3.h>

//The Window-Class should intialize and destory a window with GLFW
//TODO: Maybe we can use different window-classes for different cases, Are there different types of windows?
class Window
{
public:
	//Standard constructor, width and height are set automatically
	Window();
	//Another Constructor, manuell settings
	Window(int width, int height, const char* name);
	~Window();

	//Getter, maybe usable for debugging
	int getWidth();
	int getHeight();

	//Setter, for changing the Width and Height manually, maybe for a graphik-menu
	void setWidth(int width);
	void setHeight(int height);

	//A Getter and Setter for the name, maybe for debugging and recognition of windows
	void setName(const char* name);
	const char* getName();

	//A Method, who uses the attributes of the Window to create a GLFW-Window
	void initialize();

	//A getter for the GLFW window
	GLFWwindow* getWindow();

	//A method, to destroy the window
	void destroy();
	
private:
	int m_width, m_height;
	const char* m_name;

	GLFWwindow* m_window;

};