#include "DefinitionAndInclude.h"
#include "Renderer.h"
#include "Window.h"
#include "Shader.h"
#include "FBO.h"
#include "Node.h"
#include "Scenegraph.h"
#include "UniformManager.h"

//Example
std::vector<glm::vec3> m_vertices;

/*
measure the time for a certain number of loops
*/
double startTime = glfwGetTime();
double time = 0.0;
int i = 0;
void timeMeasuring(int numberOfLoops){
	float deltaT = glfwGetTime() - startTime;
	if (i<numberOfLoops){
		time += deltaT;
		i++;
	}
	else{
		time = (int)(time * 100) / 100.0;
		std::cout << time << "s per "<<numberOfLoops<<" loops" << std::endl;
		time = 0;
		i = 0;
	}
	startTime = glfwGetTime();
}

/*
first example:

we set a window, 
initialize the renderer and load an object, 
set the shaderhandle & give him the path of the shaders 
and renderering the object in the gameloop
*/
int main() 
{
	//our example
	m_vertices.push_back(glm::vec3(0.5, -0.5, 0.0));
	m_vertices.push_back(glm::vec3(-0.5, -0.5, 0.0));
	m_vertices.push_back(glm::vec3(0.5, 0.5, 0.0));
	m_vertices.push_back(glm::vec3(-0.5, 0.5, 0.0));

    glfwInit();

	//our window
	Window* window = new Window(550,50,800,600, "Renderer Example");
	
    glewInit();
    
	//our shader
	Shader* redShader = new Shader("//RedShader//redShader.vert", ""/*geom*/, "" /*tessC*/, ""/*tessE*/, "//RedShader//redShader.frag", ""/*com*/);

	//our renderer
	Renderer* renderer = new Renderer();
	renderer->loadObject(&m_vertices);

	int height = 800;
	//BUG!!!
	//height = window->getHeight();
	FBO fbo(height, 600);

	//Gameloop
    while( !glfwWindowShouldClose(window->getWindow()))
	{
		timeMeasuring(2000);

		//FBO
		fbo.bind();
		glViewport(0, 0, 800, 600);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		renderer->render(window->getWindow());
		fbo.unbind();

		//Szene drawen
		glViewport(0, 0, 800, 600);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		renderer->render(window->getWindow());

		glfwSwapBuffers(window->getWindow());
		glfwPollEvents();		
    }
	window->close();
    return 0;
}