#pragma once
#ifndef SHADER_H_
#define SHADER_H_
#include "stdafx.h"
class Shader {
private:
	int programID;
	GLuint loadShader(const char *fileName, GLenum type);
public:
	Shader(const char* vertexShader, const char* fragmentShader);
	void SetFloat(const char* name, float value);
	void SetInt(const char* name, int value);
	void SetMatrix(const char* name, glm::mat4 value);
	void SetVector(const char* name, glm::vec2 value);
	void SetVector(const char* name, glm::vec3 value);
	void SetVector(const char* name, glm::vec4 value);
	void SetMatrix(const char* name, glm::mat3 value);
	void UseShader();
	inline int getProgramID()  { return programID; };


};   
     
     
#endif