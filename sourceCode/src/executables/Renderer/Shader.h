#ifndef SHADER_H
#define SHADER_H

#include "DefinitionAndInclude.h"

/*
Need more Information
*/
class Shader
{
public:
	Shader(std::string vertexShaderPath, std::string geometryShaderPath, std::string tesselationControlShaderPath, std::string tesselationEvaluationShaderPath, std::string fragmentShaderPath, std::string computeShader);
	~Shader();
	void checkShader(GLuint shader);
	void loadShaderSource(GLint shader, const char* fileName);
	GLuint makeShaderProgram(bool usingVertexShader, bool usingGeometryShader, bool usingTesselationShader, bool usingFragmentShader, bool usingComputeShader);

private:
	std::string m_vertexShaderPath;
	std::string m_geometryShaderPath;
	std::string m_tesselationControlShaderPath;
	std::string m_tesselationEvaluationShaderPath;
	std::string m_fragmentShaderPath;
	std::string m_computeShaderPath;
	bool m_usingVertexShader;
	bool m_usingGeometryShader;
	bool m_usingTesselationShader;
	bool m_usingFragmentShader;
	bool m_usingComputeShader;
};
#endif