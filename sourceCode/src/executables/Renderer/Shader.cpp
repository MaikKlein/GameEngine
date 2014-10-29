#include "Shader.h"


template<typename ... Args>
void attachShaders(GLuint handle, GLuint shaderHandle, Args ...args)
{
  glAttachShader(handle, shaderHandle);
  attachShaders(handle, args...);
}
void attachShaders(GLuint handle, GLuint shaderHandle)
{
  glAttachShader(handle, shaderHandle);
}

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
  auto size = (GLint)shaderSource.size();
  glShaderSource(handle, 1, &source, &size);
  glCompileShader(handle);
  checkShader(handle);
}

ShaderProgram::ShaderProgram(const VertexShader &vs, const FragmentShader &fs)
{
  handle = glCreateProgram();
  attachShaders(handle, vs.handle, fs.handle);
  glLinkProgram(handle);
}

void ShaderProgram::bind() const
{
  glUseProgram(handle);
}

void ShaderProgram::unbind() const
{
  glUseProgram(0);
}
