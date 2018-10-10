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

Object::Object(const char * fileName, Material * m, Vector3 position, Vector3 rotation)
{
	Renderer = new MeshRenderer(fileName, m);
	transform = Transform(position, rotation, Vector3::Identity);
}

void Object::AddComponent(Component * c)
{
	ComponentList.push_back(c);
}
