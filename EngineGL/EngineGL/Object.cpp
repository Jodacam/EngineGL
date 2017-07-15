#include "stdafx.h"
#include "Object.h"

void Object::Render()
{
}

Object::Object()
{

}

void Object::RenderObjectOfType(string type)
{
	if (ObjectType == type) {
		Render();
	}
	for (auto child : Children) {
		child.second->RenderObjectOfType(type);
	}


}
