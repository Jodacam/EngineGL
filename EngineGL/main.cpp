#include "stdafx.h"
#include <iostream>
#include "EngineGL.h"
using namespace std;

int main(int argc, char **argv)
{
	OpenGLScene scene = EngineGL::CreateScene(500, 500, "Scena");
	scene.InstanciateObject("../Assets/lowpolytree.fbx", Vector3::Zero, Vector3::Zero, nullptr, "Caja");
	scene.StartUpdate();
}

