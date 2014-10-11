#ifndef SHADERHANDLE_H
#define SHADERHANDLE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>


class ShaderHandle
{
public:
	std::string vertexShaderPath;
	std::string fragmentShaderPath;
	ShaderHandle(std::string vertexShaderPath, std::string fragmentShaderPath);
	~ShaderHandle();
	GLuint createColorShaderProgram(float r, float g, float b);
	void checkShader(GLuint shaderHandle);
	void loadShaderSource(GLint shaderHandle, const char* fileName);
	GLuint makeShaderProgram(const char* vertexShaderName, const char* fragmentShaderName);
};
#endif