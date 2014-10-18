#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <windows.h> 
#include <conio.h>

#include "ShaderHandle.h"

std::string vertexShaderPath;
std::string fragmentShaderPath;

/*
initialize the shaderHandle and loads a vertex and a fragment shader
*/
ShaderHandle::ShaderHandle(std::string vertexShader, std::string fragmentShader)
{
	std::cout << "Shader was initialized" << std::endl;

	//get the Path of the exe end delete all symbols, to get the path of the sourcecode and transform it to a string, because we can add easily new chars
	char str[MAX_PATH];
	GetModuleFileNameA(NULL, str, MAX_PATH);
	for (int i = 0; i < 31; i++)
		str[strlen(str) - 1] = 0;
	std::string filePathOfSource(str);
	
	//translate the path to the shader paths
	//this->vertexShaderPath += filePathOfSource + "src\\shaders\\" + vertexShader;
	//this->fragmentShaderPath += filePathOfSource + "src\\shaders\\" + fragmentShader;
	this->vertexShaderPath += SHADERS_PATH + vertexShader;
	this->fragmentShaderPath += SHADERS_PATH +fragmentShader;

	//this->vertexShaderPath += "C:\\Users\\Marcel\\Documents\\GitHub\\GameEngine\\sourceCode\\src\\shaders\\" + vertexShader;
	//this->fragmentShaderPath += "C:\\Users\\Marcel\\Documents\\GitHub\\GameEngine\\sourceCode\\src\\shaders\\" + fragmentShader;
	//Open, compile and link Shader
	makeShaderProgram(&vertexShaderPath[0],&fragmentShaderPath[0]);
}

ShaderHandle::~ShaderHandle()
{
}

/*
just for testing
*/
GLuint ShaderHandle::createColorShaderProgram(float r, float g, float b) {
	//compile vertex shader
	const GLchar *vs_source = "\
	#version 330 \n\
	in vec4 positionAttribute;\
	void main(){\
	gl_Position = positionAttribute;\
	}";
	
	const GLint vs_source_size = strlen(vs_source);
	GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderHandle, 1, &vs_source, &vs_source_size);
	glCompileShader(vertexShaderHandle);
	checkShader(vertexShaderHandle);

	//compile fragment shader
	const GLchar *fs_source = "\
	#version 330 \n\
	out vec4 fragmentColor;\
	uniform vec3 color;\
	void main(){ \
	fragmentColor = vec4(color, 1.0);\
	}";
	
	const GLint fs_source_size = strlen(fs_source);
	GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderHandle, 1, &fs_source, &fs_source_size);
	glCompileShader(fragmentShaderHandle);
	checkShader(fragmentShaderHandle);

	//link shader programs
	GLuint programHandle = glCreateProgram();
	glAttachShader(programHandle, vertexShaderHandle);
	glAttachShader(programHandle, fragmentShaderHandle);
	glBindAttribLocation(programHandle, 0, "positionAttribute");
	glLinkProgram(programHandle);

	GLuint colorHandle = glGetUniformLocation(programHandle, "color");
	glUseProgram(programHandle);
	glUniform3f(colorHandle, r, g, b);

	return programHandle;
}

/**
* Checks a shader for compilation errors
*
* @param shaderHandle
* The id of the shader to check
*/
void ShaderHandle::checkShader(GLuint shaderHandle) {
	GLint status;
	glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &status);

	if (status == GL_FALSE) {
		GLint infoLogLength;
		glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar* infoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(shaderHandle, infoLogLength, NULL, infoLog);

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
void ShaderHandle::loadShaderSource(GLint shaderHandle, const char* fileName) {
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
	else
		std::cout << "ERROR: Unable to open file " << fileName << std::endl;

	const char* source = fileContent.c_str();
	const GLint source_size = strlen(source);

	glShaderSource(shaderHandle, 1, &source, &source_size);
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
GLuint ShaderHandle::makeShaderProgram(const char* vertexShaderName, const char* fragmentShaderName) {
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