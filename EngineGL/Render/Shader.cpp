#include "stdafx.h"
#include "Shader.h"
#include "..\auxiliar.h"


GLuint Shader::loadShader(const char * fileName, GLenum type)
{
	unsigned int fileLen;
	char *source;
	source = loadStringFromFile(fileName, fileLen);
	//////////////////////////////////////////////
	//Creación y compilación del Shader
	GLuint shader;
	shader = glCreateShader(type);
	glShaderSource(shader, 1,
		(const GLchar **)&source, (const GLint *)&fileLen);
	glCompileShader(shader);
	delete source;

	GLint compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled)
	{
		//Calculamos una cadena de error
		GLint logLen;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
		char *logString = new char[logLen];
		glGetShaderInfoLog(shader, logLen, NULL, logString);
		std::cout << "Error: " << logString << std::endl;
		delete logString;
		glDeleteShader(shader);
		//exit(-1);
	}
	return shader;
}

Shader::Shader(const char * vertexShader, const char * fragmentShader)
{

	int vertex = loadShader(vertexShader, GL_VERTEX_SHADER);
	int fragment = loadShader(fragmentShader, GL_FRAGMENT_SHADER);

	programID = glCreateProgram();
	glAttachShader(programID, vertex);
	glAttachShader(programID, fragment);
	glBindAttribLocation(programID, 0, "inPos");
	glBindAttribLocation(programID, 1, "inColor");
	glBindAttribLocation(programID, 2, "inNormal");
	glBindAttribLocation(programID, 3, "inTexCoord");
	glBindAttribLocation(programID, 4, "inTangent");
	glLinkProgram(programID);

	int linked;
	glGetProgramiv(programID, GL_LINK_STATUS, &linked);

	if (!linked)
	{
		//Calculamos una cadena de error
		GLint logLen;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLen);
		char *logString = new char[logLen];
		glGetProgramInfoLog(programID, logLen, NULL, logString);
		std::cout << "Error: " << logString << std::endl;
		delete logString;
		glDeleteProgram(programID);
		programID = 0;
		std::cin >> logString;
		exit(-1);
	}
	
	
	unsigned int dirLightIndex = glGetUniformBlockIndex(programID, "DirectionalLights");
	glUniformBlockBinding(programID, dirLightIndex, 0);

}

void Shader::SetFloat(const char * name, float value)
{
	int uniformid = glGetUniformLocation(programID, name);
	if (uniformid != -1) {
		glUniform1f(uniformid, value);
	}
	else {
		printf("Uniform value do not found");
	}
}

void Shader::SetInt(const char * name, int value)
{
	int uniformid = glGetUniformLocation(programID, name);
	if (uniformid != -1) {
		glUniform1i(uniformid, value);
	}
	else {
		printf("Uniform value do not found");
	}
}

void Shader::SetMatrix(const char * name, glm::mat4 value)
{

	int uniformid = glGetUniformLocation(programID, name);
	if (uniformid != -1) {
		glUniformMatrix4fv(uniformid, 1, GL_FALSE, &value[0][0]);
	}
	else {
		printf("Uniform value do not found");
	}

}

void Shader::SetVector(const char * name, glm::vec2 value)
{

	int uniformid = glGetUniformLocation(programID, name);
	if (uniformid != -1) {
		glUniform2fv(uniformid, 1, &value[0]);
	}
	else {
		printf("Uniform value do not found");
	}
}

void Shader::SetVector(const char * name, glm::vec3 value)
{
	int uniformid = glGetUniformLocation(programID, name);
	if (uniformid != -1) {
		glUniform3fv(uniformid, 1, &value[0]);
	}
	else {
		printf("Uniform value do not found");
	}
}

void Shader::SetVector(const char * name, glm::vec4 value)
{
	int uniformid = glGetUniformLocation(programID, name);
	if (uniformid != -1) {
		glUniform4fv(uniformid, 1, &value[0]);
	}
	else {
		printf("Uniform value do not found");
	}
}

void Shader::SetMatrix(const char * name, glm::mat3 value)
{
	int uniformid = glGetUniformLocation(programID, name);
	if (uniformid != -1) {
		glUniformMatrix4fv(uniformid, 1, GL_FALSE, &value[0][0]);
	}
	else {
		printf("Uniform value do not found");
	}
}

void Shader::UseShader()
{
	glUseProgram(programID);
}

