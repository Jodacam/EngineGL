#include "stdafx.h"
#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 direction, bool isOrthographic,float angle) {
	
	ProyectionMatrix = glm::perspective(glm::radians(angle), 1.0f, 0.1f, 1000.0f);
	ViewMatrix = glm::mat4(1.0f);
	ViewMatrix[3].x = position.x;
	ViewMatrix[3].y = position.y;
	ViewMatrix[3].z = position.z;
	ViewMatrix[3].w = 1;
	  
}
void Camera::FixedUpdate(){}