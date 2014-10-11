#include "Shader.h"

Shader::Shader()
{

}

Shader::Shader(GLuint shader_mask, const char** shaderNames)
{
	generateShader(shader_mask, shaderNames);
}

GLuint Shader::getProgramID()
{
	return m_programID;
}

Shader::~Shader()
{
	if (m_programID != NOT_ACTIVE_VALUE) glDeleteProgram(m_programID);
}

void Shader::generateShader(GLuint shader_mask, const char** shaderNames)
{
	GLuint vertexShaderID, fragmentShaderID;
}