#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define NOT_ACTIVE_VALUE 0xFFFFFFFF

//This class should initialize Shader an activate them
class Shader
{
public:
	//The constructor takes a mask and the shader-paths and use the method generateShader(...)
	Shader();
	Shader(GLuint shader_mask, const char** shaderNames);
	//If a Shader is active, the program should be deleted
	~Shader();

	void generateShader(GLuint shader_mask, const char** shaderNames);

	//A getter for the programID of the active Shader
	GLuint getProgramID();

private:
	GLuint m_programID;
};