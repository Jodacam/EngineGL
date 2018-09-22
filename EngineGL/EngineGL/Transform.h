#pragma once
#ifndef TRANSFORM_H_
#define TRANSFORM_H_
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

class Transform
{
private:

	glm::mat4 Model;
	

public:
	Transform();
	~Transform();

	glm::mat4 getModel();
	
	glm::vec3 getPosition();
};





#endif // !TRANSFORM_H_
