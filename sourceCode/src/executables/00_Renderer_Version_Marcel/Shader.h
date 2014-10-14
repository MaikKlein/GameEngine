#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <windows.h> 
#include <conio.h>

//This class should initialize Shader an activate them
class Shader
{
public:
	
	Shader();
	Shader(std::string vertexShader, std::string fragmentShader);
	~Shader();

private:
	void generateShader(const char* vertexShader, const char* fragmentShader);
	void loadShaderSource(GLint shaderID, const char* fileName);

	void checkShader(GLuint shaderID);
	void checkProgram(GLuint programID);

	GLuint getProgramID();

protected:
	GLuint m_programID;
	std::string  m_vertexShader;
	std::string m_fragmentShader;
	
};