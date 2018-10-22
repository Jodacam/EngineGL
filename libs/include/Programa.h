#ifndef PROGRAMA_H_
#define PROGRAMA_H_
#include "auxiliar.h"
#include <windows.h>
#include <gl/glew.h>
#include <gl/gl.h>
#define SOLVE_FGLUT_WARNING
#include <gl/freeglut.h> 
#include <iostream>



class Programa  {
public:
	Programa() {}
	
	//Identificadores del programa
	unsigned int vshader;
	unsigned int fshader;
	unsigned int program;
	
	//Indentificadores de Uniforms.
	int uView;
	int uModel;
	int uModelViewMat;
	int uModelViewProjMat;
	int uNormalMat;
	int PosL;
	int Inten;
	int Angle;
	int uDirfoco;
	int uColorTex;
	int uEmiTex;
	int uBumpTex;
	int uEspTex;
	int inPos;
	int inColor;
	int inNormal;
	int inTexCoord;
	int inTangent;
	
	GLuint loadShader(const char *fileName, GLenum type){
		unsigned int fileLen;
		char *source; 
		source =  loadStringFromFile(fileName, fileLen);
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
    void initShader(const char *vname, const char *fname){
		vshader = loadShader(vname, GL_VERTEX_SHADER);
		fshader = loadShader(fname, GL_FRAGMENT_SHADER);

		program = glCreateProgram();
		glAttachShader(program, vshader);
		glAttachShader(program, fshader);
		glBindAttribLocation(program, 0, "inPos");
		glBindAttribLocation(program, 1, "inColor");
		glBindAttribLocation(program, 2, "inNormal");
		glBindAttribLocation(program, 3, "inTexCoord");
		glBindAttribLocation(program, 4, "inTangent");
		glLinkProgram(program);


		int linked;
		glGetProgramiv(program, GL_LINK_STATUS, &linked);
		
		if (!linked)
		{
			//Calculamos una cadena de error
			GLint logLen;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLen);
			char *logString = new char[logLen];
			glGetProgramInfoLog(program, logLen, NULL, logString);
			std::cout << "Error: " << logString << std::endl;
			delete logString;
			glDeleteProgram(program);
			program = 0;
			exit(-1);
		}
		uModel= glGetUniformLocation(program, "model");
		uView = glGetUniformLocation(program, "View");
	    uNormalMat = glGetUniformLocation(program, "normal");
		uModelViewMat = glGetUniformLocation(program, "modelView");
		uModelViewProjMat = glGetUniformLocation(program, "modelViewProj");
	
		uColorTex = glGetUniformLocation(program, "colorTex");
		uEmiTex = glGetUniformLocation(program, "emiTex");
		uBumpTex = glGetUniformLocation(program, "normalTex");
		uEspTex = glGetUniformLocation(program, "specularTex");
		
		inTangent = glGetAttribLocation(program, "inTangent");
		inPos = glGetAttribLocation(program, "inPos");
		inColor = glGetAttribLocation(program, "inColor");
		inNormal = glGetAttribLocation(program, "inNormal");
		inTexCoord = glGetAttribLocation(program, "inTexCoord");


	}

	void ChangeUniformLocatio(const char *name, int &Location){
		Location = glGetUniformLocation(program, name);
	}

	void changeProgram()// Cambia el Programa, activan y desactivan los atributos que se usan o no.
	{
		glUseProgram(program);

		if (inPos == -1)
			glDisableVertexAttribArray(inPos);
		else
			glEnableVertexAttribArray(inPos);


		if (inColor == -1)
			glDisableVertexAttribArray(inColor);
		else
			glEnableVertexAttribArray(inColor);


		if (inNormal == -1)
			glDisableVertexAttribArray(inNormal);
		else
			glEnableVertexAttribArray(inNormal);
		
		if (inTangent == -1)
			glDisableVertexAttribArray(inTangent);
		else
			glEnableVertexAttribArray(inTangent);

		if (inTexCoord == -1)
			glDisableVertexAttribArray(inTexCoord);
		else
			glEnableVertexAttribArray(inTexCoord);

	} 
	void Destroy(){
		glDetachShader(program, vshader);
		glDetachShader(program, fshader);
		glDeleteShader(vshader);
		glDeleteShader(fshader);
		glDeleteProgram(program);
	}

};



#endif