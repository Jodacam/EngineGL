#pragma once
#ifndef VECTOR3_H_
#define VECTOR3_H_
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>


class Vector3
{
private:
	glm::vec3 realVector;

public:
	const static Vector3 Identity;
	const static Vector3 Zero;
	Vector3(float x, float y, float z);
	inline Vector3(glm::vec3 vec);
	inline Vector3();
	Vector3 operator+(Vector3 v);
	Vector3 operator-(Vector3 v);
	Vector3 operator*(float f);
	Vector3 Cross(Vector3 v);
	float Dot(Vector3 v);
	inline float getX() { return realVector.x; }
	inline float getY() { return realVector.y; }
	inline float getZ() { return realVector.z; }
	inline const glm::vec3 getRawVector() { return realVector; }

	~Vector3();

};


#endif // !VECTOR3_H:
