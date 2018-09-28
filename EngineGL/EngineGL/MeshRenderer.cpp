
#include "stdafx.h"
#include "MeshRenderer.h"

void MeshRenderer::Render( Camera* c, Transform &transform) {
	//Set up the matrix uniforms
	glm::mat4 modelView = c->getView() * transform.getModel();
	glm::mat4 modelViewProj = c->ProyectionMatrix*modelView;
	glm::mat4 normal = glm::transpose(glm::inverse(modelView));

	Shader* ActualShader = mainMaterial->getShader();
	ActualShader->UseShader();
	ActualShader->SetMatrix("modelView", modelView);
	ActualShader->SetMatrix("modelViewProj", modelViewProj);
	ActualShader->SetMatrix("normalMatrix", normal);
	mainMaterial->BlindTextures();
	mainMesh->DrawMesh();
}

MeshRenderer::MeshRenderer(const char * fileName, Material * m)
{
	mainMesh = new Mesh(fileName);
	
	mainMaterial = m;
}
