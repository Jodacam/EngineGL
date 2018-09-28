#pragma once
#ifndef OBJECT_H_
#define OBJECT_H_

#include <vector>
#include <map>
#include "Component.h"
#include "Transform.h"
#include "Camera.h"
#include "MeshRenderer.h"
using namespace std;



class Object {
private:
	vector<Component*> ComponentList;
	map<string, Object*> Children;
	string ObjectType;
	
	MeshRenderer* Renderer;
public:
		void Render(Camera* c);
		//FixedUpdate Function, Calls alwais in a infinite loop. The execution of this function do not depends on the framerate.
		void FixedUpdate();
		//Called Before FixedUpdate To Call all component Update, it can not be modified
		void InnerUpdate();
		Object(const char* fileName,Material* m);
		Transform transform;
		void AddComponent(Component* c);


	};

#endif