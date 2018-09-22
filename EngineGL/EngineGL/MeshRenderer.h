#pragma once
#ifndef MESHRENDERER_H_
#define MESHRENDERER_H_
#include "Transform.h"
#include "Mesh.h"
#include "Material.h"
#include "Camera.h"
class MeshRenderer {
	private:
		Mesh* mainMesh;
		Material* mainMaterial;
	public:
		 //Render this Mesh in the camera view 
		void Render(const Camera* c, Transform &transform);
		MeshRenderer(const char* fileName, Material* m);


};
#endif // !MESHRENDERER_H_