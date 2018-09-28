#include "stdafx.h"
#include "CameraTransform.h"


CameraTransform::CameraTransform()
{
	
	CameraTransform(Vector3::Zero, Vector3::Zero, Vector3::Identity);

	
}

CameraTransform::CameraTransform(Vector3 position, Vector3 rotation, Vector3 scale)
{
	glm::vec3 realp = position.getRawVector();
	glm::vec3 actualDirection;
	XYZRotation = rotation.getRawVector();
	actualDirection.x = cos(glm::radians(XYZRotation.x)) * cos(glm::radians(XYZRotation.y));
	actualDirection.y = sin(glm::radians(XYZRotation.x));
	actualDirection.z = cos(glm::radians(XYZRotation.x)) * sin(glm::radians(XYZRotation.y));
	actualDirection = glm::normalize(actualDirection);
	Model  = glm::lookAt(realp, realp + actualDirection, glm::vec3(0, 1, 0));
}





CameraTransform::~CameraTransform()
{
}

void CameraTransform::Rotate(Vector3 rotation)
{
	glm::vec3 p = glm::vec3(glm::inverse(Model)[3]);
	Model = glm::rotate(Model, rotation.getZ(), glm::vec3(0, 0, 1));
	Model = glm::rotate(Model, rotation.getX(), glm::vec3(1, 0, 0));
	Model = glm::rotate(Model, rotation.getY(), glm::vec3(0, 1, 0));
	std::cout << p.x << " " << p.y << " " << p.z << " ";
}

void CameraTransform::Translate(Vector3 translation)
{
	glm::vec3 actualDirection;
	
	glm::vec3 p = glm::vec3(glm::inverse(Model)[3]) + translation.getRawVector();
	actualDirection.x = cos(glm::radians(XYZRotation.x)) * cos(glm::radians(XYZRotation.y));
	actualDirection.y = sin(glm::radians(XYZRotation.x));
	actualDirection.z = cos(glm::radians(XYZRotation.x)) * sin(glm::radians(XYZRotation.y));
	actualDirection = glm::normalize(actualDirection);
	Model = glm::lookAt(p, p + actualDirection, glm::vec3(0, 1, 0));


}
