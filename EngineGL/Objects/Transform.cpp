#include "stdafx.h"
#include "Transform.h"

void Transform::UpdateModel()
{
	
	Model = TranslationMatrix* RotationMatrix*ScaleMatrix;
}

Transform::Transform()
{
	Transform(Vector3::Zero, Vector3::Zero, Vector3::Identity);
}


Transform::Transform(Vector3 position, Vector3 rotation, Vector3 scale)
{
	
	glm::vec4 translation = glm::vec4(position.getRawVector(),1);
	TranslationMatrix[3] = translation;
	glm::scale(ScaleMatrix, scale.getRawVector());
	glm::vec3 radiansVector = glm::radians(rotation.getRawVector());

	RotationMatrix = glm::toMat4(glm::quat(radiansVector));
	Model = TranslationMatrix*RotationMatrix*ScaleMatrix;

}

Transform::~Transform()
{

}

glm::mat4 Transform::getModel()
{
	return Model;
}

Vector3 Transform::getPosition()
{
	return Vector3(glm::vec3(Model[3]));
}

Vector3 Transform::getRotation()
{
	
	glm::vec3 rotation = glm::eulerAngles(glm::toQuat(RotationMatrix));
	return Vector3(rotation);
}

Vector3 Transform::getScale()
{
	glm::vec3 scale = glm::vec3(ScaleMatrix[0][0], ScaleMatrix[1][1], ScaleMatrix[2][2]);
	return Vector3(scale);
}

void Transform::Translate(Vector3 translation)
{
	TranslationMatrix = glm::translate(TranslationMatrix, translation.getRawVector());
	UpdateModel();
}

void Transform::Rotate(Vector3 rotation)
{
	glm::mat4 newRotate = glm::toMat4(glm::quat(glm::radians(rotation.getRawVector())));
	RotationMatrix *= newRotate;
	UpdateModel();
}

void Transform::Scale(Vector3 scale)
{
	ScaleMatrix = glm::scale(ScaleMatrix, scale.getRawVector());
	UpdateModel();

}

void Transform::SetPosition(Vector3 position)
{
	TranslationMatrix[4] = glm::vec4(position.getRawVector(), 1);
	UpdateModel();
}

void Transform::SetRotation(Vector3 rotation)
{
	glm::vec3 radiansVector = glm::radians(rotation.getRawVector());
	RotationMatrix = glm::toMat4(glm::quat(radiansVector));
	UpdateModel();
}

void Transform::SetScale(Vector3 scale)
{
	ScaleMatrix = glm::scale(glm::mat4(1.0f), scale.getRawVector());
}

