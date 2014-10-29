#include "Shader.h"

/*
initialize the shader and loads a vertex, geometry, tesselation, fragment & compute shader
if you don't want to use a shader, then set the string to ""
*/
Shader::Shader(std::string vertexShaderPath, std::string geometryShaderPath, std::string tesselationControlShaderPath, std::string tesselationEvaluationShaderPath, std::string fragmentShaderPath, std::string computeShaderPath)
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

	if (tesselationControlShaderPath != "" && tesselationEvaluationShaderPath != ""){
		m_tesselationControlShaderPath += SHADERS_PATH + tesselationControlShaderPath;
		m_tesselationEvaluationShaderPath += SHADERS_PATH + tesselationEvaluationShaderPath;
		m_usingTesselationShader = true;
	}
	else{
		m_usingTesselationShader = false;
	}

	if (computeShaderPath != ""){
		m_computeShaderPath += SHADERS_PATH + computeShaderPath;
	}
	else{
		m_usingComputeShader = false;
	}

	//Open, compile and link the neccesary Shader
	makeShaderProgram(m_usingVertexShader, m_usingGeometryShader, m_usingTesselationShader, m_usingFragmentShader, m_usingComputeShader);
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

/*
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
GLuint Shader::makeShaderProgram(bool usingVertexShader, bool usingGeometryShader, bool usingTesselationShader, bool usingFragmentShader, bool usingComputeShader) {

	GLuint vertexShaderID, geometryShaderID, tesselationControlShaderID, tesselationEvaluationShaderID, fragmentShaderID, computeShaderID;

	if (usingVertexShader){
		//compile vertex shader
		const char* vertexShaderName = &m_vertexShaderPath[0];
		vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		loadShaderSource(vertexShaderID, vertexShaderName);
		glCompileShader(vertexShaderID);
		checkShader(vertexShaderID);
	}

	if (usingGeometryShader){
		//compile geometry shader
		const char* geometryShaderName = &m_geometryShaderPath[0];
		geometryShaderID = glCreateShader(GL_GEOMETRY_SHADER);
		loadShaderSource(geometryShaderID, geometryShaderName);
		glCompileShader(geometryShaderID);
		checkShader(geometryShaderID);
	}

	if (usingTesselationShader){
		//compile tesselation shader
		const char* tesselationControlShaderName = &m_tesselationControlShaderPath[0];
		tesselationControlShaderID = glCreateShader(GL_TESS_CONTROL_SHADER);
		loadShaderSource(tesselationControlShaderID, tesselationControlShaderName);
		glCompileShader(tesselationControlShaderID);
		checkShader(tesselationControlShaderID);

		const char* tesselationEvaluationShaderName = &m_tesselationEvaluationShaderPath[0];
		tesselationEvaluationShaderID = glCreateShader(GL_TESS_EVALUATION_SHADER);
		loadShaderSource(tesselationEvaluationShaderID, tesselationEvaluationShaderName);
		glCompileShader(tesselationEvaluationShaderID);
		checkShader(tesselationEvaluationShaderID);

	}

	if (usingFragmentShader){
		//compile fragment shader
		const char* fragmentShaderName = &m_fragmentShaderPath[0];
		fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		loadShaderSource(fragmentShaderID, fragmentShaderName);
		glCompileShader(fragmentShaderID);
		checkShader(fragmentShaderID);
	}

	if (usingComputeShader){
		//compile compute shader
		const char* computeShaderName = &m_computeShaderPath[0];
		computeShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		loadShaderSource(computeShaderID, computeShaderName);
		glCompileShader(computeShaderID);
		checkShader(computeShaderID);
	}

	//link shader programs
	GLuint programHandle = glCreateProgram();

	if (m_usingVertexShader)
		glAttachShader(programHandle, vertexShaderID);
	if (m_usingGeometryShader)
		glAttachShader(programHandle, geometryShaderID);
	if (m_usingTesselationShader)
		glAttachShader(programHandle, tesselationControlShaderID);
	if (m_usingTesselationShader)
		glAttachShader(programHandle, tesselationEvaluationShaderID);
	if (m_usingFragmentShader)
		glAttachShader(programHandle, fragmentShaderID);
	if (m_usingComputeShader)
		glAttachShader(programHandle, computeShaderID);
	
	glLinkProgram(programHandle);
	glUseProgram(programHandle);

	//return programHandle;
	return programHandle;
}