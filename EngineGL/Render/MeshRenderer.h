#pragma once
#ifndef MESHRENDERER_H_
#define MESHRENDERER_H_
#include "..\Objects\Transform.h"
#include "Mesh.h"
#include "Material.h"
#include "..\Objects\Camera.h"
class MeshRenderer {
	private:
		
		Material* mainMaterial;
	public:
		Mesh * mainMesh;
		 //Render this Mesh in the camera view 
		void Render( Camera* c, Transform &transform);
		MeshRenderer(const char* fileName, Material* m);


};
#endif // !MESHRENDERER_H_
