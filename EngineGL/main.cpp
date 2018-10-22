#include "stdafx.h"
#include <iostream>
#include "EngineGL.h"
using namespace std;

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}
int main(int argc, char **argv)
{

	OpenGLScene scene = EngineGL::CreateScene(500, 500, "Scena");
	scene.InstanciateObject("../Assets/Crate1.obj", Vector3::Zero, Vector3::Zero, nullptr, "Caja");
	scene.StartUpdate();

}

