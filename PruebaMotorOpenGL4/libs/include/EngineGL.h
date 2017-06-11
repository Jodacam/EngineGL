#pragma once
#ifndef  ENGINEGL_H_
#define ENGINEGL_H_
#define ENGINE_GL __declspec(dllexport)
 // EngineGL_H_
#include <gl/glew.h>
#include <gl/gl.h>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <assimp/cimport.h>
#define SOLVE_FGLUT_WARNING
#include <gl/freeglut.h> 
#include <iostream>
#include <cstdlib>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
namespace EngineGL {

	ENGINE_GL void InitGLContext();
	ENGINE_GL void ChangeCamera(glm::mat4 positionMatrix);




}
#endif