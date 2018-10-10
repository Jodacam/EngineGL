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
GLuint ubo;

std::vector<IRenderEvent*> renderEvent;
using namespace std;
DirrectionalLight LuzPrueba;
Shader* Diffuse;
namespace EngineGL
{


	void Start() {			
		
		
		glutMotionFunc(motionFunc);
		glutReshapeFunc(resizeFunc);
		glutDisplayFunc(renderFunc);
		glutIdleFunc(idleFunc);
		glutKeyboardFunc(keyboardFunc);
		glutMouseFunc(mouseFunc);
		glGenBuffers(1, &ubo);
		glBindBuffer(GL_UNIFORM_BUFFER, ubo);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(DirrectionalLight), &LuzPrueba, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
		glBindBufferRange(GL_UNIFORM_BUFFER, 0, ubo, 0, sizeof(DirrectionalLight));
		glutMainLoop();
		
	}

	 OpenGLScene CreateScene(int width, int height, const char* name)
	{
		return  OpenGLScene(width,height,name);
	}
	 
	  void BindRenderEvent(IRenderEvent * event)
	 {
		  renderEvent.push_back(event);
		  
	 }
	
	void InitGLContext(int argc, char ** argv)
	{		
		glutInit(&argc, argv);
		glutInitContextVersion(4, 2);
		glutInitContextProfile(GLUT_CORE_PROFILE);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	}


	int OpenWindow(int w, int h,const char* name ) {
		glutInitWindowSize(w, h);
		glutInitWindowPosition(0, 0);
		int id = glutCreateWindow(name);
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			std::cout << "Error: " << glewGetErrorString(err) << std::endl;
		}
		const GLubyte *oglVersion = glGetString(GL_VERSION);
		cout << "This system supports OpenGL Version: " << oglVersion << std::endl;

		glEnable(GL_DEPTH_TEST);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glFrontFace(GL_CCW);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnable(GL_CULL_FACE);
		return id;
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

	 void SetRenderFunc(void(*func)())
	{
		 glutDisplayFunc(func);
	}



	

}


	void renderFunc() {	
		for each (auto var in renderEvent)
		{
			(*var)();
		}
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
					
			break;
		case 's':
			
			break;
		case 'a':
						
			break;
		case 'd':
			
			break;
		default:
			
			break;
		}
		glutPostRedisplay();
	}
	void mouseFunc(int button, int state, int x, int y) {
		ClickInfomation click;
		click.button = button;
		click.x = x;
		click.y = y;
		click.state = state;
		glutPostRedisplay();


	}


void motionFunc(int x, int y) {
	
	glutPostRedisplay();
}



