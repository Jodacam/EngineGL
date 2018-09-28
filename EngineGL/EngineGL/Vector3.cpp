#include "stdafx.h"
#include "Vector3.h"
const Vector3 Vector3::Identity = Vector3(1, 1, 1);
const Vector3 Vector3::Zero = Vector3(0, 0, 0);

Vector3::Vector3(float x, float y, float z)
{
	realVector = glm::vec3(x, y, z);
}

Vector3::Vector3(glm::vec3 vec)
{
	realVector = vec;
}

inline Vector3::Vector3()
{
	realVector = glm::vec3(0, 0, 0);
}

Vector3 Vector3::operator+(Vector3 v)
{	
	return Vector3(realVector.x + v.getX(),  realVector.y + v.getY(), realVector.z + v.getZ());
}

Vector3 Vector3::operator-(Vector3 v)
{
	return Vector3(realVector.x - v.getX(), realVector.y - v.getY(), realVector.z - v.getZ());
}

Vector3 Vector3::operator*(float f)
{
	glm::vec3 a = realVector*f;
	return Vector3(a);
}

Vector3 Vector3::Cross(Vector3 v)
{
	glm::vec3 auxiliar = glm::cross(realVector, v.getRawVector());
	return Vector3(auxiliar);
}

float Vector3::Dot(Vector3 v)
{	 
	return glm::dot(realVector, v.getRawVector());
}

Vector3::~Vector3()
{
	
}
