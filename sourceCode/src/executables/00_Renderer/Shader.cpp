#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <windows.h> 
#include <conio.h>

#include "Shader.h"

/*
initialize the shaderHandle and loads a vertex and a fragment shader
*/
Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
	std::cout << "Shader was initialized" << std::endl;

	//set the Path of the shaders
	m_vertexShaderPath += SHADERS_PATH + vertexShaderPath;
	m_fragmentShaderPath += SHADERS_PATH +fragmentShaderPath;
	
	//Open, compile and link Shader
	makeShaderProgram(&m_vertexShaderPath[0],&m_fragmentShaderPath[0]);
}

/*
initialize the shaderHandle and loads a vertex, geometry, tesselation & fragmen shader
if you don't want to use a geometry & fragment shader, then set the string to ""
*/
Shader::Shader(std::string vertexShaderPath, std::string geometryShaderPath, std::string tesselationShaderPath, std::string fragmentShaderPath)
{
	std::cout << "Shader was initialized" << std::endl;

	//check which shader we are using and set the path of the shaders
	if (vertexShaderPath != ""){
		m_vertexShaderPath += SHADERS_PATH + vertexShaderPath;
		m_usingVertexShader = true;
	}
	else{
		m_usingVertexShader = false;
	}	
	if (fragmentShaderPath != ""){
		m_fragmentShaderPath += SHADERS_PATH + fragmentShaderPath;
		m_usingFragmentShader = true;
	}
	else{
		m_usingFragmentShader = false;
	}
	if (geometryShaderPath != ""){
		m_geometryShaderPath += SHADERS_PATH + geometryShaderPath;
		m_usingGeometryShader = true;
	}
	else{
		m_usingGeometryShader = false;
	}

	if (tesselationShaderPath != ""){
		m_tesselationShaderPath += SHADERS_PATH + tesselationShaderPath;
		m_usingTesselationShader = true;
	}
	else{
		m_usingTesselationShader = false;
	}

	//Open, compile and link the neccesary Shader
//	makeShaderProgram(m_usingVertexShader, m_usingGeometryShader, m_usingTesselationShader, m_usingFragmentShader);
}

Shader::~Shader()
{
}

/*
* Checks a shader for compilation errors
*
* @param shaderHandle
* The id of the shader to check
*/
void Shader::checkShader(GLuint shader) {
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

/**
* Reads a file and returns the content as a pointer to chars
*
* @param shaderHandle
* The id of a created shader
*
* @param fileName
* The path and filename to a shader file.
* \n Recommendation: Define compiler flag @c -D"SHADERS_PATH" and call
* @a SHADERS_PATH"[filename]"
*/
void Shader::loadShaderSource(GLint shader, const char* fileName) {
	std::string fileContent;
	std::string line;

	//open file and "parse" input
	std::ifstream file(fileName);
	if (file.is_open()) {
		while (!file.eof()){
			getline(file, line);
			fileContent += line + "\n";
		}
		file.close();
		std::cout << "SUCCESS: Opened file " << fileName << std::endl;
	}
	else{
		std::cout << "ERROR: Unable to open file " << fileName << std::endl;
	}

	const char* source = fileContent.c_str();
	const GLint source_size = strlen(source);

	glShaderSource(shader, 1, &source, &source_size);
}

/**
* A combination of loadShaderSource(), checkShader() and shader compilation.
*
* @param  vertexShaderName
* The path and filename to a vertex shader file.
* \n Recommendation: Define compiler flag @c -D"SHADERS_PATH" and call
* @a SHADERS_PATH"[filename]"
*
* @param  fragmentShaderName
* The path and filename to a fragment shader file.
*
* @return
* The id of a created the shader program
*/
GLuint Shader::makeShaderProgram(const char* vertexShaderName, const char* fragmentShaderName) {
	//compile vertex shader
	GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	loadShaderSource(vertexShaderHandle, vertexShaderName);
	glCompileShader(vertexShaderHandle);
	checkShader(vertexShaderHandle);

	//compile fragment shader
	GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	loadShaderSource(fragmentShaderHandle, fragmentShaderName);
	glCompileShader(fragmentShaderHandle);
	checkShader(fragmentShaderHandle);

	//link shader programs
	GLuint programHandle = glCreateProgram();
	glAttachShader(programHandle, vertexShaderHandle);
	glAttachShader(programHandle, fragmentShaderHandle);
	glLinkProgram(programHandle);

	glUseProgram(programHandle);

	//return programHandle;
	return programHandle;
}