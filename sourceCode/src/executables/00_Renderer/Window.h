#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	GLFWwindow* m_window;
	const char* m_name;
	int m_width;
	int m_height;
	int m_xpos;
	int m_ypos;

	Window(int xpos, int ypos, int height, int width, const char* name);
	~Window();
	GLFWwindow* getWindow();
	void update();
	void close();

	void setName(const char* name);
	const char* getName();
	void setWidth(int width);
	int getWidth();
	void setHeight(int height);
	int getHeight();
	void setXpos(int xpos);
	int getXpos();
	void setYpos(int ypos);
	int getYpos();
};
#endif