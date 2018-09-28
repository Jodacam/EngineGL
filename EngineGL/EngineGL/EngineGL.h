#pragma once
#ifndef ENGINEGL_H_
#define ENGINEGL_H_
#define ENGINE_GL __declspec(dllexport)
 // EngineGL_H_
#include <gl/glew.h>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <assimp/cimport.h>
#define SOLVE_FGLUT_WARNING
#include <gl/freeglut.h> 
#include <iostream>
#include <cstdlib>
#include "Object.h"
#include "Camera.h"
namespace EngineGL {

	
	ENGINE_GL void InitGLContext(int argc, char ** argv);
	
	ENGINE_GL void SetIdleFunc(void(*func)());
	
	ENGINE_GL void SetMouseFunc(void(*func)(int button, int state, int x, int y));
	
	ENGINE_GL void SetMotionFunc(void(*func)(int x, int y));

	ENGINE_GL void AddObject(const char* fileName);

	ENGINE_GL void Start();
}
#endif