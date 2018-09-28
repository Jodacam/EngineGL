#pragma once
#include "Transform.h"
class CameraTransform :
	public Transform
{
private:
	glm::vec3 XYZRotation;
public:
	CameraTransform();
	CameraTransform(Vector3 position, Vector3 rotation, Vector3 scale);
	~CameraTransform();

	void Rotate(Vector3 rotation);
	void Translate(Vector3 translation);
};

