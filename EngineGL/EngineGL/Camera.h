#pragma once
#ifndef CAMERA_H_
#define CAMERA_H_
#include "Object.h"

class Camera : Object {
private:


public:
	Camera(glm::vec3 postion, glm::vec3 direction, bool isOrthographic);

};
#endif // !CAMERA_H_
