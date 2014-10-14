
#include "Renderer.h"

Renderer::Renderer()
{
	useOpenGL33();
	initializeWindow();
	printInformation();
}

Renderer::Renderer(std::string vertexShader, std::string fragmentShader, Object* object)
{
	useOpenGL33();
	initializeWindow();
	printInformation();
	initializeShader(vertexShader, fragmentShader);
	m_object = object;
}

Renderer::~Renderer()
{

}


void Renderer::render(GLFWwindow* window, Object* object)
{

	object->render(window);
}


void Renderer::useOpenGL33()
{
#ifdef __APPLE__
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glewExperimental = GL_TRUE;
#endif
}



void Renderer::printInformation()
{
	std::cout << "=============================================" << std::endl;
	// print out some info about the graphics drivers
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "=============================================" << std::endl;
}

Window* Renderer::getWindow()
{
	return m_window;
}

void Renderer::initializeWindow()
{
	glfwInit();
	m_window = new Window(800, 600, "Renderer");
	m_window->initialize();
	glewInit();
}

void Renderer::initializeShader(std::string vertexShader, std::string fragmentShader)
{
	m_shader = new Shader(vertexShader, fragmentShader);
}

void Renderer::start()
{
	while (!glfwWindowShouldClose(m_window->getWindow()))
	{
		render(m_window->getWindow(), m_object);
	}
	m_window->destroy();
}