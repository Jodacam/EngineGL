#include "stdafx.h"
#include "Transform.h"

Transform::Transform()
{
	Model = glm::mat4();
	Model[3].z = 5;
	Model[3].w = 1;
}

Transform::~Transform()
{

}

glm::mat4 Transform::getModel()
{
	return Model;
}

glm::vec3 Transform::getPosition()
{
	return glm::vec3(Model[4]);
}
