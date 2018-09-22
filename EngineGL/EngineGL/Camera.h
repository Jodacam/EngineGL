#pragma once
#ifndef CAMERA_H_
#define CAMERA_H_


class Camera{
private:


public:
	glm::mat4 ProyectionMatrix;
	glm::mat4 ViewMatrix;
	Camera(glm::vec3 position, glm::vec3 direction, bool isOrthographic,float angle);

	void FixedUpdate();

};
#endif // !CAMERA_H_
