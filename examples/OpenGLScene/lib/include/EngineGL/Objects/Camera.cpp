#include "stdafx.h"
#include "Camera.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 direction, bool isOrthographic,float angle) {
	
	if(!isOrthographic)
	ProyectionMatrix = glm::perspective(angle, 1.0f, 0.1f, 100.0f);
	else
	{
		ProyectionMatrix = glm::ortho(-10, 10, -10, 10,0,1000);
	}
	
	
	transform = Transform(Vector3(position),Vector3(direction),Vector3::Identity);
	UpdateView();
	  
}

void Camera::UpdateView()
{
	viewMatrix = glm::inverse(transform.getModel());
}
