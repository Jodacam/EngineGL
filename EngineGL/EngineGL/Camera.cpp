#include "stdafx.h"
#include "Camera.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 direction, bool isOrthographic,float angle) {
	
	ProyectionMatrix = glm::perspective(glm::radians(angle), 1.0f, 0.1f, 1000.0f);
	
	transform = CameraTransform(Vector3(position),Vector3(direction),Vector3::Identity);
	  
}
