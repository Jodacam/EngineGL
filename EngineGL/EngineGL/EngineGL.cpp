// EngineGL.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"
#include "EngineGL.h"
struct DirrectionalLight
{	
	glm::vec3 Dir;
	glm::vec3 Color;
	glm::vec3 CameraDir;

};
//Funciones de interrupción, Estan declaradas arriba por que así es las coge siempre bien 
void renderFunc();
void resizeFunc(int width, int height);
void idleFunc();
void keyboardFunc(unsigned char key, int x, int y);
void mouseFunc(int button, int state, int x, int y);
void motionFunc(int x, int y);
//Punteros a función, asi el usuario de la Libreria puede definir sus propias funciones
void(*keyf)(unsigned char key, int x, int y);
void(*mousef)(int button, int state, int x, int y);
void(*idlef)();
void(*motionf)(int x, int y);
void(*resizef)(int w, int h);
enum class RenderType { FORWARD_RENDER, DEFERED_RENDER };
RenderType TypeofRender = RenderType::FORWARD_RENDER;

vector<Object*> ObjectList;

GLuint ubo;
Camera* MainCamera;
using namespace std;
DirrectionalLight LuzPrueba;
Shader* Diffuse;
namespace EngineGL
{
	
	void Start() {	
		
		glutMainLoop();
		
	}
	void CreateCamera(glm::vec3 position, glm::vec3 direction, bool isOrthographic, float angle) {
		MainCamera = new Camera(position, direction, isOrthographic, angle);
	}
	void InitGLContext(int argc, char ** argv)
	{
		CreateCamera(glm::vec3(0, 0, -10), glm::vec3(0,180.0f,0), false, 90.0f);
		LuzPrueba.Color = glm::vec3(0, 0, 1);
		LuzPrueba.Dir = glm::vec3(1, -1, 0);
		LuzPrueba.CameraDir = glm::vec3( MainCamera->getView()*glm::vec4(LuzPrueba.Dir,0));
		glutInit(&argc, argv);
		glutInitContextVersion(4, 2);
		glutInitContextProfile(GLUT_CORE_PROFILE);

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
		glutInitWindowSize(500, 500);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("EngineGL");

		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			std::cout << "Error: " << glewGetErrorString(err) << std::endl;
			
		}
		const GLubyte *oglVersion = glGetString(GL_VERSION);
		cout << "This system supports OpenGL Version: " << oglVersion << std::endl;
		glutMotionFunc(motionFunc);
		glutReshapeFunc(resizeFunc);
		glutDisplayFunc(renderFunc);
		glutIdleFunc(idleFunc);
		glutKeyboardFunc(keyboardFunc);
		glutMouseFunc(mouseFunc);
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glFrontFace(GL_CCW);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnable(GL_CULL_FACE);
		ubo = 0;		
	    Diffuse = new Shader("../shaders/Default.vs", "../shaders/Default.fs");		
		
		glGenBuffers(1, &ubo);
		glBindBuffer(GL_UNIFORM_BUFFER, ubo);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(DirrectionalLight), &LuzPrueba,GL_DYNAMIC_DRAW );
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
		glBindBufferRange(GL_UNIFORM_BUFFER,0,ubo,0,sizeof(DirrectionalLight));
		
	}

	

	void SetKeyFuction(void(*func)(unsigned char key, int x, int y))
	{
		keyf = func;
	}

	void SetIdleFunc(void(*func)()) {
		idlef = func;
	}

	void SetMouseFunc(void(*func)(int button, int state, int x, int y))
	{
		mousef = func;
	}

	void SetMotionFunc(void(*func)(int x, int y))
	{
		motionf = func;

	}

	 void AddObject(const char * fileName)
	{
		 Object* o = new Object(fileName,new Material(Diffuse));
		 ObjectList.push_back(o);
	}

	

}


	void renderFunc() {	
		MainCamera->UpdateView();
		LuzPrueba.CameraDir = glm::vec3(MainCamera->getView()*glm::vec4(LuzPrueba.Dir, 0));
		glBindBuffer(GL_UNIFORM_BUFFER, ubo);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(DirrectionalLight), &LuzPrueba, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
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


// Termina el NameSpace, Aqui van las funciones auxiliares.
	void resizeFunc(int width, int height) {
		glutPostRedisplay();
	}
	void idleFunc() {
		
		glutPostRedisplay();

	}
	void keyboardFunc(unsigned char key, int x, int y) {
		switch (key)
		{
		case 'w':
			ObjectList[0]->transform.Rotate(Vector3(0, 1, 0));		
			break;
		case 's':
			ObjectList[0]->transform.Rotate(Vector3(0, -1, 0));
			break;
		case 'a':
			LuzPrueba.Color = glm::vec3(1, 0, 0);			
			break;
		case 'd':
			MainCamera->transform.Rotate(Vector3(0, 1, 0));
			break;
		default:
			
			break;
		}
		glutPostRedisplay();
	}
	void mouseFunc(int button, int state, int x, int y) {
		
		glutPostRedisplay();


	}


void motionFunc(int x, int y) {
	
	glutPostRedisplay();
}



