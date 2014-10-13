#include "Window.h"

Window::Window()
{
	m_width = 800;
	m_height = 600;

	m_name = "Windows";

}

Window::Window(int width, int height, const char* name)
{
	m_width = width;
	m_height = height;
	m_name = name;
}

Window::~Window()
{

}

int Window::getWidth()
{
	return m_width;
}
void Window::setWidth(int width)
{
	m_width = width;
}

int Window::getHeight()
{
	return m_height;
}


void Window::setHeight(int height)
{
	m_height = height;
}

void Window::setName(const char* name)
{
	m_name = name;
}
const char* Window::getName()
{
	return m_name;
}

void Window::initialize(){

	m_window = glfwCreateWindow(m_width, m_height, m_name, 0, 0);
	glfwSetWindowPos(m_window,300, 50);
	glfwMakeContextCurrent(m_window);
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
}

GLFWwindow* Window::getWindow()
{
	return m_window;
}

void Window::destroy()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}