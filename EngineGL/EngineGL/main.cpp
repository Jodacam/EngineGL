#include "stdafx.h"
#include <iostream>
#include "EngineGL.h"
using namespace std;
int main(int argc, char **argv)
{
	/*EngineGL::InitGLContext(argc, argv);
	EngineGL::AddObject("../Assets/Crate1.obj");
	EngineGL::Start();*/
	OpenGLScene scene = EngineGL::CreateScene(500, 500, "Scena");
	scene.InstanciateObject("../Assets/Crate1.obj", Vector3::Zero, Vector3::Zero, nullptr, "Caja");
	scene.StartUpdate();

	
	string s;
	cin >> s;
	return 0;
}