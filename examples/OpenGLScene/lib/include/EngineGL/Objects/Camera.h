#pragma once
#ifndef CAMERA_H_
#define CAMERA_H_
#include "Transform.h"

class Camera{
private:
	glm::mat4 ProyectionMatrix;
	glm::mat4 viewMatrix;
public:
	
	
	Transform transform;
	Camera(glm::vec3 position, glm::vec3 direction, bool isOrthographic,float angle);
	inline glm::mat4 getView() { return viewMatrix; };
	inline glm::mat4 getProyectionMatrix () { return ProyectionMatrix; }
	void UpdateView();
	

};
#endif // !CAMERA_H_
