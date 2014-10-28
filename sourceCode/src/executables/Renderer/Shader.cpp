#include "Shader.h"


std::string loadShaderSource(std::string path)
{
  std::ifstream input(path);
  std::string source((std::istreambuf_iterator<char>(input)),
    std::istreambuf_iterator<char>());
  return source;
}

void checkShader(GLuint shader) {
  GLint status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

  if (status == GL_FALSE) {
    GLint infoLogLength;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

    GLchar* infoLog = new GLchar[infoLogLength + 1];
    glGetShaderInfoLog(shader, infoLogLength, NULL, infoLog);

    std::cout << "ERROR: Unable to compile shader" << std::endl << infoLog << std::endl;
    delete[] infoLog;
  }
  else {
    std::cout << "SUCCESS: Shader compiled" << std::endl;
  }
}
BaseShader::BaseShader(const std::string &shaderSource, ShaderType shaderType)
{
  handle = glCreateShader(shaderType);
  auto source = shaderSource.c_str();
  auto size   = (GLint)shaderSource.size();
  glShaderSource(handle, 1, &source, &size);
  glCompileShader(handle);
  checkShader(handle);
}

ShaderProgram::ShaderProgram(const VertexShader &vs, const FragmentShader &fs)
{
  handle = glCreateProgram();
  glAttachShader(handle,vs.handle);
  glAttachShader(handle,fs.handle);
  glLinkProgram(handle);
}

void ShaderProgram::bind()
{
  glUseProgram(handle);
}

void ShaderProgram::unbind()
{
  glUseProgram(0);
}
