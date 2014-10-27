#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
	Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
	Shader(std::string vertexShaderPath, std::string geometryShaderPath, std::string tesselationShaderPath, std::string fragmentShaderPath);
	~Shader();
	void checkShader(GLuint shader);
	void loadShaderSource(GLint shader, const char* fileName);
	GLuint makeShaderProgram(const char* vertexShaderName, const char* fragmentShaderName);
private:
	std::string m_vertexShaderPath;
	std::string m_geometryShaderPath;
	std::string m_tesselationShaderPath;
	std::string m_fragmentShaderPath;
	bool m_usingVertexShader;
	bool m_usingGeometryShader;
	bool m_usingTesselationShader;
	bool m_usingFragmentShader;
};
#endif