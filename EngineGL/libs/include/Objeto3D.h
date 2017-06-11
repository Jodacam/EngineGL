#ifndef OBJETO3D_H_
#define OBJETO3D_H_
#include "auxiliar.h"
#include "Programa.h"
#include <windows.h>
#include <gl/glew.h>
#include <gl/gl.h>
#define SOLVE_FGLUT_WARNING
#include <gl/freeglut.h> 
#include <iostream>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define M_PI 3.1416


class Objeto3D{
public:
	//VAO
	unsigned int vao;
	// VBO
	unsigned int posVBO;
	unsigned int TangVBO;
	unsigned int colorVBO;
	unsigned int normalVBO;
	unsigned int texCoordVBO;
	unsigned int triangleIndexVBO;
	 int colorTexId;
	 int emiTexId;
	 int NorTexId;
	 int EspTexId;
	//Atributos geometricos.
	int NTindex;
	
	glm::mat4 model;

	
	void initObj(const int NVertex, const float* VertexPos, const float* VertexColor, const float* VertexNormal, const float* VertexTexCoord, 
		const int NTriangleIndex,const unsigned int *TriangleIndex, const float *VertexTang){
		NTindex = NTriangleIndex;
			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);

			glGenBuffers(1, &posVBO);
			glBindBuffer(GL_ARRAY_BUFFER, posVBO);
			glBufferData(GL_ARRAY_BUFFER, NVertex * sizeof(float)* 3,
				VertexPos, GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
			glEnableVertexAttribArray(0);
		
			glGenBuffers(1, &colorVBO);
			glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
			glBufferData(GL_ARRAY_BUFFER, NVertex * sizeof(float)* 3,
				VertexColor, GL_STATIC_DRAW);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
			glEnableVertexAttribArray(1);
		
			glGenBuffers(1, &normalVBO);
			glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
			glBufferData(GL_ARRAY_BUFFER, NVertex * sizeof(float)* 3,
				VertexNormal, GL_STATIC_DRAW);
			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
			glEnableVertexAttribArray(2);
		
			glGenBuffers(1, &texCoordVBO);
			glBindBuffer(GL_ARRAY_BUFFER, texCoordVBO);
			glBufferData(GL_ARRAY_BUFFER, NVertex * sizeof(float)* 2,
				VertexTexCoord, GL_STATIC_DRAW);
			glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0, 0);
			glEnableVertexAttribArray(3);
		

			glGenBuffers(1, &TangVBO);
			glBindBuffer(GL_ARRAY_BUFFER, TangVBO);
			glBufferData(GL_ARRAY_BUFFER, NVertex * sizeof(float)* 3,
				VertexTang, GL_STATIC_DRAW);
			glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 0, 0);
			glEnableVertexAttribArray(4);
			
			
			
			glGenBuffers(1, &triangleIndexVBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangleIndexVBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER,
				NTriangleIndex * sizeof(unsigned int)* 3, TriangleIndex,
				GL_STATIC_DRAW);
		
			model = glm::mat4(1.0f);
			
			
			colorTexId = -1;
			emiTexId = -1;
			NorTexId = -1;
			EspTexId = -1;
		}


	unsigned int loadTex(const char *fileName){
		unsigned char *map;
		unsigned int w, h;
		map = loadTexture(fileName, w, h);

		if (!map)  {
			std::cout << "Error cargando el fichero: " << fileName << std::endl;
			exit(-1);
		}

		unsigned int texId;
		glGenTextures(1, &texId);
		glBindTexture(GL_TEXTURE_2D, texId);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, (GLvoid*)map);
		delete[] map;

		glGenerateMipmap(GL_TEXTURE_2D);
		//Anisotrópico
		GLint num = 0;

		glGetIntegerv(GL_NUM_EXTENSIONS, &num);

		bool found = false;

		while (0<--num & !found) {
			if (strcmp(((char *)glGetStringi(GL_EXTENSIONS, num - 1)), "GL_EXT_texture_filter_anisotropic"))
				found = true;
			//std::cout << glGetStringi( GL_EXTENSIONS, num - 1 ) << std::endl; 
		}

		if (found) {
			GLfloat fLargest;
			glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &fLargest);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
			printf("App::Load > %.0fx Anistropic filtering supported.", fLargest);
		}
		else {
			printf("Anistropic filtering Not supported");
		}



		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		return texId;
	}
	glm::mat4 ChangeModel(const glm::mat4 &b){
		model = b;
		return model;
	}

	glm::mat4 Transalte(glm::vec3 a){
		model = glm::translate(model,a);
		return model;
	}

	glm::mat4 Rotate(const float &x, const float &y, const float &z){
		model = glm::rotate(model, x, glm::vec3(1, 0, 0));
		model = glm::rotate(model, y, glm::vec3(0, 1, 0));
		model = glm::rotate(model, z, glm::vec3(0, 0, 1));
		return model;
	}

	glm::mat4 Rotate(const float &angle, const glm::vec3 &rot){
		model = glm::rotate(model, angle, rot);
		
		return model;
	}


	void render( Programa &program2, const glm::mat4 &view, const glm::mat4 &Proy){
		glm::mat4 modelView = view*model;
		glm::mat4 modelViewProj = Proy*view*model;
		glm::mat4 normal = glm::transpose(glm::inverse(modelView));
		program2.changeProgram();
		if (program2.uView != -1)
			glUniformMatrix4fv(program2.uView, 1, GL_FALSE, &view[0][0]);

		if (program2.uModel != -1)
			glUniformMatrix4fv(program2.uModel, 1, GL_FALSE, &model[0][0]);


		if (program2.uModelViewMat != -1)
			glUniformMatrix4fv(program2.uModelViewMat, 1, GL_FALSE,
			&(modelView[0][0]));
		if (program2.uModelViewProjMat != -1)
			glUniformMatrix4fv(program2.uModelViewProjMat, 1, GL_FALSE,
			&(modelViewProj[0][0]));
		if (program2.uNormalMat != -1)
			glUniformMatrix4fv(program2.uNormalMat, 1, GL_FALSE,
			&(normal[0][0]));

		if (colorTexId != -1){
			if (program2.uColorTex != -1)  {

				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, colorTexId);
				glUniform1i(program2.uColorTex, 0);
			}
		}
		if (program2.uEmiTex != -1)  {
			glActiveTexture(GL_TEXTURE0 +1);
			glBindTexture(GL_TEXTURE_2D, emiTexId);
			glUniform1i(program2.uEmiTex, 1);
		}
		if (program2.uBumpTex != -1)  {
			glActiveTexture(GL_TEXTURE0 + 2);
            glBindTexture(GL_TEXTURE_2D, NorTexId);
			glUniform1i(program2.uBumpTex, 2);
		}


		if (program2.uEspTex != -1)  {
			glActiveTexture(GL_TEXTURE0 + 3);
			glBindTexture(GL_TEXTURE_2D, EspTexId);
			glUniform1i(program2.uEspTex, 3);
		}

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, NTindex * 3,

			GL_UNSIGNED_INT, (void*)0);

	
	
	
	}
	
	
	
	
	
	void AddDifuTex(const char *Tx){
		colorTexId = loadTex(Tx);

}

	void AddEmitex(const char *Tx){ 
		emiTexId = loadTex(Tx); 
	
	}

	void AddNormalTex(const char *Tx){
		NorTexId = loadTex(Tx); }

	void AddEspTex(const char *Tx){
		EspTexId = loadTex(Tx);
	}



	void renderWithSpot(Programa &program2, glm::mat4 &view, glm::mat4 &Proy, glm::vec3 &Aux, glm::vec3 &color,float &angle,glm::vec3 &dir){
		glm::mat4 modelView = view*model;
		glm::mat4 modelViewProj = Proy*view*model;
		glm::mat4 normal = glm::transpose(glm::inverse(modelView));
		program2.changeProgram();

		if (program2.uView != -1)
			glUniformMatrix4fv(program2.uView, 1, GL_FALSE, &view[0][0]);

		if (program2.uModel != -1)
			glUniformMatrix4fv(program2.uModel, 1, GL_FALSE, &model[0][0]);
		
		if (program2.uModelViewMat != -1)
			glUniformMatrix4fv(program2.uModelViewMat, 1, GL_FALSE,
			&(modelView[0][0]));
		
				
		if (program2.uModelViewProjMat != -1)
			glUniformMatrix4fv(program2.uModelViewProjMat, 1, GL_FALSE,
			&(modelViewProj[0][0]));
		if (program2.uNormalMat != -1)
			glUniformMatrix4fv(program2.uNormalMat, 1, GL_FALSE,
			&(normal[0][0]));
		
		
		
		
		if (program2.PosL != -1)
		{
			glUniform3fv(program2.PosL, 1, &(Aux.x));

		}
		if (program2.Inten != -1)
		{
			glUniform3fv(program2.Inten, 1, &(color.x));
		}

		
		if (program2.Angle != -1){

			glUniform1f(program2.Angle, angle);

		}

		if (program2.uDirfoco != -1)
		{
			glUniform3fv(program2.uDirfoco, 1, &(dir.x));

		}
		
		if (colorTexId != -1){
			if (program2.uColorTex != -1)  {

				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, colorTexId);
				glUniform1i(program2.uColorTex, 0);
			}
		}
		if (program2.uEmiTex != -1)  {
			glActiveTexture(GL_TEXTURE0 + 1);
			glBindTexture(GL_TEXTURE_2D, emiTexId);
			glUniform1i(program2.uEmiTex, 1);
		}
		if (program2.uBumpTex != -1)  {
			glActiveTexture(GL_TEXTURE0 + 2);


			glBindTexture(GL_TEXTURE_2D, NorTexId);
			glUniform1i(program2.uBumpTex, 2);
		}


		if (program2.uEspTex != -1)  {
			glActiveTexture(GL_TEXTURE0 + 3);


			glBindTexture(GL_TEXTURE_2D, EspTexId);
			glUniform1i(program2.uEspTex, 3);
		}

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, NTindex * 3,

			GL_UNSIGNED_INT, (void*)0);




	}
	void Destroy(){
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		 glDeleteBuffers(1, &posVBO);
		glDeleteBuffers(1, &colorVBO);
	    glDeleteBuffers(1, &normalVBO);
	    glDeleteBuffers(1, &texCoordVBO);
		glDeleteBuffers(1, &triangleIndexVBO);
		glBindVertexArray(0);
		glDeleteVertexArrays(1, &vao);
	
	
	}
};
#endif // !OBJETO3D_H_
