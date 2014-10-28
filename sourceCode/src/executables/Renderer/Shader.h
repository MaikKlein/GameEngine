#ifndef SHADER_H
#define SHADER_H

#include "Defs.h"
#include <string>

enum ShaderType{
  VERTEX_SHADER = 0x8B31,
  FRAGMENT_SHADER = 0x8B30,
  GEOMETRY_SHADER = 0x8DD9,
};
// Loads the shader source from a location
std::string loadShaderSource(std::string path);

/// FIXME: Doesn't check properly - Validates the shader 
void checkShader(GLuint shader);

struct BaseShader{
  GLuint handle;
  BaseShader(const std::string &shaderSource, ShaderType shaderType);
};
struct VertexShader : public BaseShader{
  VertexShader(const std::string &shaderSource) : BaseShader(shaderSource, VERTEX_SHADER){}
};
struct FragmentShader : public BaseShader{
  FragmentShader(const std::string &shaderSource) : BaseShader(shaderSource, FRAGMENT_SHADER){}
};
struct GeometryShader : public BaseShader{
  GeometryShader(const std::string &shaderSource) : BaseShader(shaderSource, GEOMETRY_SHADER){}
};
/**
TODO: Add additional shader
*/

// Shader program
struct ShaderProgram{
  GLuint handle;
  ShaderProgram(const VertexShader &vs, const FragmentShader &fs);
  void bind();
  void unbind();
};

#endif