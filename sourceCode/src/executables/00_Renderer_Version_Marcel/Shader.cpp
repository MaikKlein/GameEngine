#include "Shader.h"

Shader::Shader()
{

}

Shader::Shader (std::string vertexShader, std::string fragmentShader)
{

	//My Standard Path for shaders
//	m_vertexShader += "C:\\Users\\Marcel\\Documents\\GitHub\\GameEngine\\sourceCode\\src\\shaders\\"+vertexShader;
//	m_fragmentShader += "C:\\Users\\Marcel\\Documents\\GitHub\\GameEngine\\sourceCode\\src\\shaders\\"+ fragmentShader;

	m_vertexShader += SHADERS_PATH + vertexShader;
	m_fragmentShader += SHADERS_PATH + fragmentShader;

	generateShader(&m_vertexShader[0],&m_fragmentShader[0]);
	
}

Shader::~Shader()
{
  glDeleteProgram(m_programID);
}

void Shader::generateShader(const char* vertexShader, const char* fragmentShader)
{
	//Two IDs are generated
	GLuint vertexShaderID, fragmentShaderID;

		//...the vertexShader is created
		vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		//the shaderNames provide the paths, from this paths we load the shader-data
		loadShaderSource(vertexShaderID, vertexShader);
		glCompileShader(vertexShaderID);
		//finally we check, if everything went ok
		checkShader(vertexShaderID);


		//...the fragmentShader is created the same way as the vertex
		fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		loadShaderSource(fragmentShaderID, fragmentShader);
		glCompileShader(fragmentShaderID);
		checkShader(fragmentShaderID);

	//after the shaders are created, we have to link the program
	m_programID = glCreateProgram();
	//the shader will be attached
	glAttachShader(m_programID, vertexShaderID);
	glAttachShader(m_programID, fragmentShaderID);
	
	//the programm will be linked and activated
	glLinkProgram(m_programID);
	glUseProgram(m_programID);
	//we check another time, if everything went right
	checkProgram(m_programID);
}

void Shader::loadShaderSource(GLint shaderID, const char* fileName)
{
	std::string fileContent;
	std::string line;

	std::ifstream file(fileName);
	if (file.is_open())
	{
		//We read the file and save the content in fileContent
		while (!file.eof())
		{
			getline(file, line);
			fileContent += line + "\n";
		}
		file.close();
		std::cout << "SUCCESS: The file was opened" << fileName << std::endl;
	}
	else
		std::cout << "FAILUR: The file could not be opened" << fileName << std::endl;

	const char* source = fileContent.c_str();
	const GLint source_size = strlen(source);

	//we read the source and saved it in fileContent, this we give to another OpenGL method
	glShaderSource(shaderID, 1, &source, &source_size);
}

void Shader::checkShader(GLuint shaderID)
{
	GLint status;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);

	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar* infoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(shaderID, infoLogLength, NULL, infoLog);

		std::cout << "FAILURE: The Shader cannot be compiled" << std::endl << infoLog << std::endl;
		delete[] infoLog;
	}
	else
	{
		std::cout << "SUCCESS: The Shader was compiled" << std::endl;
	}
}

void Shader::checkProgram(GLuint programID)
{
	GLint status;
	glGetProgramiv(programID, GL_LINK_STATUS, &status);

	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar* infoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(programID, infoLogLength, NULL, infoLog);

		std::cout << "FAILURE: The Program could not be linked" << std::endl << infoLog << std::endl;
		delete[] infoLog;
	}
	else
	{
		std::cout << "SUCCESS: The Program was linked" << std::endl;
	}
}

GLuint Shader::getProgramID()
{
	return m_programID;
}