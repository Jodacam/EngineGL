#include "stdafx.h"
#include "OpenGLScene.h"
#include "EngineGL.h"
void OpenGLScene::renderFunc()
{	
	glutSetWindow(windowId);
		MainCamera->UpdateView();
		if (TypeofRender == RenderType::FORWARD_RENDER) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//Subimos las Luces al Shader
			for (int i = 0; i < ObjectList.size(); i++) {
				ObjectList[i]->Render(MainCamera);
			}
		}
		glUseProgram(NULL);
		glutSwapBuffers();
}
OpenGLScene::OpenGLScene()
{

}

OpenGLScene::OpenGLScene(int width, int height, const char * sceneName)
{
	EngineGL::InitGLContext(0, nullptr);
	windowId = EngineGL::OpenWindow(width, height, sceneName);
	MainCamera = new Camera(glm::vec3(0, 0, -10), glm::vec3(0, 180.0f, 0), false, 90.0f);
	Diffuse = new Shader("../shaders/Default.vs", "../shaders/Default.fs");
	EngineGL::BindRenderEvent(new OnRenderEvent<OpenGLScene>(this, &OpenGLScene::renderFunc));

}

OpenGLScene::~OpenGLScene()
{
}

Object* OpenGLScene::InstanciateObject(const char * fileName, Vector3 position, Vector3 rotation, Material * mat, const char * name)
{
	Object* o = new Object(fileName, new Material(Diffuse), position, rotation);
	ObjectList.push_back(o);
	return o;
}

Object * OpenGLScene::InstanciateObject(const char * fileName, Material * mat, const char * name)
{
	return nullptr;
}

Object * OpenGLScene::InstanciateObject(Mesh * mesh, Material * mat, const char * name)
{
	return nullptr;
}

Object * OpenGLScene::InstanciateObject(Mesh * mesh, Vector3 position, Vector3 rotation, Material * mat, const char * name)
{
	return nullptr;
}



//Starts the Main Loop of the Scene
void OpenGLScene::StartUpdate()
{
	EngineGL::Start();
}
