#pragma once
#ifndef FBO_H_
#define FBO_H_
#include <windows.h>
#include <gl/glew.h>
#include <gl/gl.h>
#define SOLVE_FGLUT_WARNING
#include <gl/freeglut.h> 
#include <iostream>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <cstdlib>



class Fbo {
public:
	int ucolorBuffTexId;
	int uvertexBuffTexId;
	int uespeBuffTexId;
	int uemisBuffTexId;
	int unormalBuffTexId;
	unsigned int fbo;
	unsigned int colorBuffTexId;
	unsigned int depthBuffTexId;
	unsigned int vertexBuffTexId;
	unsigned int espeBuffTexId;
	unsigned int emisBuffTexId;
	unsigned int normalBuffTexId;
	unsigned int BumpBuffTexId;

	
	void initFBO() {
		glGenFramebuffers(1, &fbo);
		ucolorBuffTexId    =  1;
		uvertexBuffTexId   =  1;
		uespeBuffTexId	   =  1;
		uemisBuffTexId	   =  1;
		unormalBuffTexId   =  1;
		glGenTextures(1, &depthBuffTexId);
		
		/**/ glGenTextures(1, &colorBuffTexId);
		glGenTextures(1, &depthBuffTexId);
		glGenTextures(1, &vertexBuffTexId);
		glGenTextures(1, &espeBuffTexId);
		glGenTextures(1, &emisBuffTexId);
		glGenTextures(1, &normalBuffTexId);
	//*/
	}
	void resize(unsigned int w, unsigned int h) {
		
		
		if (ucolorBuffTexId !=-1) {
			glBindTexture(GL_TEXTURE_2D, colorBuffTexId);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0,
				GL_RGBA, GL_FLOAT, NULL);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		}


		if (uemisBuffTexId != -1) {
			glBindTexture(GL_TEXTURE_2D, emisBuffTexId);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0,
				GL_RGBA, GL_FLOAT, NULL);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}


		if (uespeBuffTexId = -1) {
			glBindTexture(GL_TEXTURE_2D, espeBuffTexId);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0,
				GL_RGBA, GL_FLOAT, NULL);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		}

		if (unormalBuffTexId = -1) {
			glBindTexture(GL_TEXTURE_2D, normalBuffTexId);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB32F, w, h, 0,
				GL_RGBA, GL_UNSIGNED_BYTE, 0);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		}
		
		if (uvertexBuffTexId = -1) {

			glBindTexture(GL_TEXTURE_2D, vertexBuffTexId);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB32F, w, h, 0,
				GL_RGBA, GL_UNSIGNED_BYTE, 0);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		}

		if (unormalBuffTexId = -1) {
			glBindTexture(GL_TEXTURE_2D, BumpBuffTexId);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, w, h, 0,
				GL_RGBA, GL_UNSIGNED_BYTE, 0);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		}


		glBindTexture(GL_TEXTURE_2D, depthBuffTexId);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, w, h, 0,
			GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);	
		
		
		//if (ucolorBuffTexId !=-1)
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
			GL_TEXTURE_2D, colorBuffTexId, 0);
		
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D,
			depthBuffTexId, 0);
		//if (uvertexBuffTexId != -1)
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2,
			GL_TEXTURE_2D, vertexBuffTexId, 0);
		//if (unormalBuffTexId != -1)
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1,
			GL_TEXTURE_2D, normalBuffTexId, 0);
		
		//if (uespeBuffTexId != -1)
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT4,
			GL_TEXTURE_2D, espeBuffTexId, 0);
		
		//if (uemisBuffTexId != -1)
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT3,
			GL_TEXTURE_2D, emisBuffTexId, 0);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT5,
			GL_TEXTURE_2D, BumpBuffTexId, 0);


		const GLenum buffs[6] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3, GL_COLOR_ATTACHMENT4,GL_COLOR_ATTACHMENT5 };
		glDrawBuffers(6, buffs);
		if (GL_FRAMEBUFFER_COMPLETE != glCheckFramebufferStatus(GL_FRAMEBUFFER))
		{
			std::cerr << "Error configurando el FBO" << std::endl;
			//exit(-1);
		}
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void UseColorText() {
		glGenTextures(1, &colorBuffTexId);
		ucolorBuffTexId = 1;
}
	void UseEspecular() {
		glGenTextures(1, &espeBuffTexId);
		uespeBuffTexId = 1;
	}
	void UseNormal() {
		glGenTextures(1, &normalBuffTexId);
		ucolorBuffTexId = 1;
	}
	void UseEmisive() {
		glGenTextures(1, &emisBuffTexId);
		ucolorBuffTexId = 1;
	}
	void UseVertex() {
		glGenTextures(1, &vertexBuffTexId);
		ucolorBuffTexId = 1;
	}

	void destroy() {

		glDeleteFramebuffers(1, &fbo);
		glDeleteTextures(1, &colorBuffTexId);
		glDeleteTextures(1, &depthBuffTexId);
		glDeleteTextures(1, &vertexBuffTexId);
		glDeleteTextures(1, &BumpBuffTexId);
		glDeleteTextures(1, &normalBuffTexId);
		glDeleteTextures(1, &espeBuffTexId);
		glDeleteTextures(1, &emisBuffTexId);
	}
};


#endif // FBO_H_
