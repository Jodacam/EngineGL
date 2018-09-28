#pragma once
#ifndef TRANSFORM_H_
#define TRANSFORM_H_
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "Vector3.h"

class Transform
{
protected:

	glm::mat4 Model;
	glm::mat4 TranslationMatrix;
	glm::mat4 ScaleMatrix;
	glm::mat4 RotationMatrix;
	void UpdateModel();

public:
	Transform();
	Transform(Vector3 position,Vector3 rotation,Vector3 scale);
	~Transform();

	glm::mat4 getModel();
	
	Vector3 getPosition();
	Vector3 getRotation();
	Vector3 getScale();

	void Translate(Vector3 translation);
	void Rotate(Vector3 rotation);
	void Scale(Vector3 scale);
	void SetPosition(Vector3 position);
	void SetRotation(Vector3 rotation);
	void SetScale(Vector3 scale);
};





#endif // !TRANSFORM_H_
