
#ifndef MOTORAPI_H_
#define MOTORAPI_H_
#define MOTOR_API __declspec(dllexport) 
#include <windows.h>
#include "auxiliar.h"
#include <gl/glew.h>
#include <gl/gl.h>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <assimp/cimport.h>
#define SOLVE_FGLUT_WARNING
#include <gl/freeglut.h> 
#include <iostream>
#include "Objeto3D.h"
#include "PLANE.h"
#include "Programa.h"
#include "ProgramaDS.h"
#include "Fbo.h"
#include <cstdlib>

namespace Motorapi {

	MOTOR_API void Init(int argc, char** argv);

	MOTOR_API int AddObj(const int NVertex, const float* VertexPos, const float* VertexColor, const float* VertexNormal, const float* VertexTexCoord,
		const int NTriangleIndex, const unsigned int *TriangleIndex, const float *VertexTang);

	MOTOR_API void SetResize(void(*func)(int w, int h));
	
	MOTOR_API void SetKeyFuction(void(*func)(unsigned char key, int x, int y));

	MOTOR_API int AddObj(const char *File);

	MOTOR_API void mainLoop();

	MOTOR_API void ChangeView(glm::mat4 v);
	
	MOTOR_API void ChangeProjection(glm::mat4 v);

	MOTOR_API void ChangeModelObj(int ObjIden,glm::mat4 mod);

	MOTOR_API void AddDifuseText(int ObjIden, const char *File);

	MOTOR_API void AddBumpText(int ObjIden, const char *File);

	MOTOR_API void AddEspcText(int ObjIden, const char *File);
	
	MOTOR_API void AddEmisiveText(int ObjIden, const char *File);
	
	MOTOR_API int AddPointLight(glm::vec3 Pos, glm::vec3 Color);

	MOTOR_API int AddDirectionalLight(glm::vec3 Dir, glm::vec3 Color);

	MOTOR_API int AddSpotLight(glm::vec3 Pos, glm::vec3 Color,glm::vec3 Dir, float angle);

	MOTOR_API void ChangeShader(const char *vert, const char *frag);

	MOTOR_API void ChangeDeferedShader(const char *vert, const char *frag);

	MOTOR_API void SetIdleFunc(void(*func)());

	MOTOR_API void SetMouseFunc(void(*func)(int button, int state, int x, int y));

	MOTOR_API void SetMotionFunc(void(*func)(int x, int y));

	MOTOR_API void ChangePointLight(int id,glm::vec3 Pos, glm::vec3 Color);

	MOTOR_API void ChangeDirectionalLight(int id,glm::vec3 Dir, glm::vec3 Color);

	MOTOR_API void ChangeSpotLight(int id,glm::vec3 Pos, glm::vec3 Color, glm::vec3 Dir, float angle);





}

#endif
