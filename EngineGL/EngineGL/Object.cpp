#include "stdafx.h"
#include "Object.h"


void Object::InnerUpdate()
{
	for (Component* c : ComponentList) {
		c->UpdateComponent();
	}
}

Object::Object(const char* fileName, Material* m)
{
	Renderer = new MeshRenderer(fileName, m);

	transform = Transform();
}

void Object::Render(Camera* c)
{
	Renderer->Render(c, transform);
}

void Object::AddComponent(Component * c)
{
	ComponentList.push_back(c);
}
