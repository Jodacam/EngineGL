#pragma once
#ifndef CAMERA_H_
#define CAMERA_H_
#include "CameraTransform.h"

class Camera{
private:


public:
	glm::mat4 ProyectionMatrix;
	
	CameraTransform transform;
	Camera(glm::vec3 position, glm::vec3 direction, bool isOrthographic,float angle);
	inline glm::mat4 getView() { return transform.getModel(); };
	

};
#endif // !CAMERA_H_
