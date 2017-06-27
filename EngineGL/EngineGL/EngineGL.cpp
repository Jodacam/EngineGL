// EngineGL.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"
#include "EngineGL.h"

int NumeroCosos = 21;
const std::string HOLA = "Hola me llamo pepe";
void(*keyf)(unsigned char key, int x, int y);
void(*mousef)(int button, int state, int x, int y);
void(*idlef)();
void(*motionf)(int x, int y);
void(*resizef)(int w, int h);

namespace EngineGL{
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
	std::cout << "This system supports OpenGL Version: " << oglVersion << std::endl;
	std::string Hola;	
	std::cin >> Hola;

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
