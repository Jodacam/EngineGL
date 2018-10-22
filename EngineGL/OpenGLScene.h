#pragma once
#ifndef OPENGLSCENE_H_
#define OPENGLSCENE_H_
#include "Objects\Object.h"

using namespace std;
enum class RenderType { FORWARD_RENDER, DEFERED_RENDER };
class OpenGLScene
{
private:
	vector<Object*> ObjectList;
	Camera* MainCamera;	
	Shader* Diffuse;
	void renderFunc();
	RenderType TypeofRender = RenderType::FORWARD_RENDER;
	int windowId;


public:
	OpenGLScene();
	OpenGLScene(int width, int height,const char* sceneName);
	virtual ~OpenGLScene();
	//Create an object in the scene reading a mesh, setting position and rotation, returns the object created
	Object* InstanciateObject(const char* fileName, Vector3 position, Vector3 rotation, Material* mat,const char* name);
	//Creates an object at (0,0,0)
	Object* InstanciateObject(const char* fileName, Material* mat, const char* name);
	//Creates an object at (0,0,0)
	Object* InstanciateObject(Mesh* mesh, Material* mat, const char* name);
	//Create an object in the scene using a mesh, setting position and rotation
	Object* InstanciateObject(Mesh* mesh,Vector3 position,Vector3 rotation, Material* mat, const char* name);

	void StartUpdate();
};














#endif // !OPENGLSCENE_H_






