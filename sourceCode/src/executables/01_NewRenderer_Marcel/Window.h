#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*
Every Window class provides a window object of the GLFWwindow Class. It will be used for renderer purposes
and to manage the changes the user does.
*/
class Window
{
public:
	///Constructor for a Window, which needs a width, height, a name and a position
	/*m_xpos, m_ypos, m_height, m_width, m_name will be set by the user*/
	Window(int xpos, int ypos, int height, int width, const char* name);
	~Window();

	/// A getter for the GLFWwindow
	/*Returns the m_window attribute of the Window class*/
	GLFWwindow* getWindow();

	//Nicht notwendig, oder? Macht ja die GLFWwindow klasse
	///This Method recognize changes of the window like size etc.
	void update();

	///This method close the window completely
	void close();
	

	///A Setter for the Name of the Window
	void setName(const char* name);
	///A getter for m_name
	const char* getName();
	///A Setter for the Width of the Window
	void setWidth(int width);
	///A getter for m_width
	int getWidth();
	///A Setter for the Height of the Window
	void setHeight(int height);
	///A getter for m_height
	int getHeight();
	///A Setter for the XPOS of the Window
	void setXpos(int xpos);
	///A getter for m_xpos
	int getXpos();
	///A Setter for the Ypos of the Window
	void setYpos(int ypos);
	///A getter for m_ypos
	int getYpos();

protected:
	GLFWwindow* m_window;
	const char* m_name;

	int m_width;
	int m_height;
	int m_xpos;
	int m_ypos;
};
#endif