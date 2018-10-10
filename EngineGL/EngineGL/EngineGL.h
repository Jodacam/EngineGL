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
#include "IEvent.h"
#include "OpenGLScene.h"
namespace EngineGL {

	//Starts the OpenGL Context. 
	ENGINE_GL void InitGLContext(int argc, char ** argv);

	//Set the primary idle function. This will be executed each frame. 
	ENGINE_GL void SetIdleFunc(void(*func)());

	//Set the primary click function, button is the button clicked, state is the click state (Press or unpress) an x,y 
	// are the position at screen in pixels. It will be called before any ClickEvent. If you want to Bind a Object to the
	// Click Input, use BindClickEvent(IClickEvent) instead
	ENGINE_GL void SetMouseFunc(void(*func)(int button, int state, int x, int y));


	ENGINE_GL void SetMotionFunc(void(*func)(int x, int y));

	//Set the primary Render Function. It will be called before any RenderEvent, it only admits statics function and not
	//member functions. If you want to use them, use BindRenderEvent instead.
	ENGINE_GL void SetRenderFunc(void(*func)());	

	//Open a OpenGL Window. Returns the identificator. If you want to use that window  SetActiveWindow(int id)
	ENGINE_GL int OpenWindow(int w, int h, const char* name);

	//Start the render Main loop, All lines write after this won't be executed
	//because glut enters you into a infinite loop. You can use the Bind Funtions to use the event callbacks.
	ENGINE_GL void Start();

	/*Creates a new OpenGL Scene with all the funcionality OnBuild, you only need to add Objects and Ligths

	*/
	ENGINE_GL OpenGLScene CreateScene(int width,int height,const char* name);

	//
	ENGINE_GL void BindRenderEvent(IRenderEvent* event);


}
#endif