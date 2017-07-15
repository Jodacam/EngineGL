#pragma once
#ifndef OBJECT_H_
#define OBJECT_H_
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace std;
class Object {
private:
	glm::mat4 Model;
	map<string, Object*> Children;
	string ObjectType;
	void Render();
public:
		Object();
		void RenderObjectOfType(string type);
	};

#endif