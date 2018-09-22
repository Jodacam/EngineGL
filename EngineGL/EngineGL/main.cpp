#include "stdafx.h"
#include <iostream>
#include <MotorApi.h>
#include "EngineGL.h"
using namespace std;
int main(int argc, char **argv)
{
	EngineGL::InitGLContext(argc, argv);
	EngineGL::AddObject("../Assets/Crate1.obj");
	EngineGL::Start();
	
	string s;
	cin >> s;
	return 0;
}