#ifndef WINDOW_H
#define WINDOW_H

#include "DefinitionAndInclude.h"

/*
Need more Information
*/
class Window
{
public:
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
private:
	GLFWwindow* m_window;
	const char* m_name;
	int m_width;
	int m_height;
	int m_xpos;
	int m_ypos;
};
#endif