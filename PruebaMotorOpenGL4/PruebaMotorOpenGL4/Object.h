#pragma once
#ifndef OBJECT_H_
#define OBJECT_H_
#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;
class Object {
private:
	map<string, Object*> Children;
	string ObjectType;
	void Render();
public:
		Object();
		void RenderObjectOfType(string type);
	};

#endif