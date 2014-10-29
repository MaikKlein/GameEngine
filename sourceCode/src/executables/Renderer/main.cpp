#include "Defs.h"
#include "Renderer.h"
#include "Window.h"
#include "Shader.h"            
#include "Buffer.hpp"
#include "FBO.h"

//Example

/*
measure the time for a certain number of loops
*/
double startTime = glfwGetTime();
double time = 0.0;
int i = 0;
void timeMeasuring(int numberOfLoops){
  float deltaT = glfwGetTime() - startTime;
  if (i < numberOfLoops){
    time += deltaT;
    i++;
  }
  else{
    time = (int)(time * 100) / 100.0;
    std::cout << time << "s per " << numberOfLoops << " loops" << std::endl;
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
  std::vector<glm::vec3> vertices;
  vertices.push_back(glm::vec3(0.5, -0.5, 0.0));
  vertices.push_back(glm::vec3(-0.5, -0.5, 0.0));
  vertices.push_back(glm::vec3(0.5, 0.5, 0.0));
  vertices.push_back(glm::vec3(-0.5, 0.5, 0.0));


  glfwInit();

  //our window
  Window window(550, 50, 800, 600, "Renderer Example");

  glewInit();

  VertexShader vs(loadShaderSource(SHADERS_PATH + std::string("//ColorShader//colorShader.vert")));
  FragmentShader fs(loadShaderSource(SHADERS_PATH + std::string("//ColorShader//colorShader.frag")));
  ShaderProgram p(vs, fs);
  //our renderer
  OpenGL3Context context;
  Renderer renderer(context);
  Buffer<glm::vec3> buffer(vertices,STATIC_DRAW);

  //FBO fbo(800, 600);

  //Gameloop
  while (!glfwWindowShouldClose(window.getWindow()))
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    timeMeasuring(2000);
    renderer.draw(buffer,p);
    glfwSwapBuffers(window.getWindow());
    glfwPollEvents();
  }

  window.close();
  return 0;
}