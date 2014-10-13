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
	//The constructor takes the Path of a vertex and a fragment shader
	Shader();
	Shader(std::string vertexShader, std::string fragmentShader);
	//If a Shader is active, the program should be deleted
	~Shader();

private:
	//This method should generate a Vertex and a Fragment Shader
	void generateShader(const char* vertexShader, const char* fragmentShader);
	//This metod uses a file to load the source of the shader
	void loadShaderSource(GLint shaderID, const char* fileName);

	//Two methods which check if the generation and linking of shader and program were successfull
	void checkShader(GLuint shaderID);
	void checkProgram(GLuint programID);

	//A getter for the programID of the active Shader
	GLuint getProgramID();

protected:
	GLuint m_programID;
	std::string  m_vertexShader;
	std::string m_fragmentShader;
	
};