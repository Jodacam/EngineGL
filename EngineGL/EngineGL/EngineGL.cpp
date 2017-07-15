// EngineGL.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"
#include "EngineGL.h"
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



using namespace std;
namespace EngineGL
{

	
	void InitGLContext(int argc, char ** argv)
	{
		glutInit(&argc, argv);
		glutInitContextVersion(4, 5);
		glutInitContextProfile(GLUT_CORE_PROFILE);

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
		glutInitWindowSize(500, 500);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("EngineGL");

		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			std::cout << "Error: " << glewGetErrorString(err) << std::endl;
			exit(-1);
		}
		const GLubyte *oglVersion = glGetString(GL_VERSION);
		cout << "This system supports OpenGL Version: " << oglVersion << std::endl;
		glutMotionFunc(motionFunc);
		glutReshapeFunc(resizeFunc);
		//glutDisplayFunc(renderFunc);
		glutIdleFunc(idleFunc);
		glutKeyboardFunc(keyboardFunc);
		glutMouseFunc(mouseFunc);
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glFrontFace(GL_CCW);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnable(GL_CULL_FACE);
		cout << "Patata";
		string Hola;
		cin >> Hola;

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
}
// Termina el NameSpace, Aqui van las funciones auxiliares.
	void resizeFunc(int width, int height) {
		glutPostRedisplay();
	}
	void idleFunc() {
		idlef();
		glutPostRedisplay();

	}
	void keyboardFunc(unsigned char key, int x, int y) {
		keyf(key, x, y);
		glutPostRedisplay();
	}
	void mouseFunc(int button, int state, int x, int y) {
		mousef(button, state, x, y);
		glutPostRedisplay();


	}


void motionFunc(int x, int y) {
	motionf(x, y);
	glutPostRedisplay();
}
