#include "Renderer.h"

/*
by initializing, the renderer check, if the OS support OpenGL
*/

void OpenGL3Context::bindContext() const{
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glewExperimental = GL_TRUE;
}
Renderer::Renderer(const RenderContext &context)
{
  context.bindContext();
  printInfo();
}

/*
print Information about the supported OpenGL & GLSL version, Vendor and Renderer
*/
void Renderer::printInfo(){

  std::cout << "=============================================" << std::endl;
  // print out some info about the graphics drivers
  std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
  std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
  std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
  std::cout << "=============================================" << std::endl;
}



