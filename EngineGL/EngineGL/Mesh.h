#pragma once
#ifndef MESH_H_
#define MESH_H_

class Mesh {
	private:
		//Identifiers of the VBO
		Assimp::Importer importer;
		const aiScene* scene;
		unsigned int vaoID;
		unsigned int posVBO;
		unsigned int TangVBO;
		unsigned int colorVBO;
		unsigned int normalVBO;
		unsigned int texCoordVBO;
		unsigned int triangleIndexVBO;
		int NTindex;
		void initMesh(const int NVertex, const float* VertexPos, const float* VertexColor, const float* VertexNormal, const float* VertexTexCoord,
			const int NTriangleIndex, const unsigned int *TriangleIndex, const float *VertexTang);
	public:
		Mesh(const char* fileName);
		void DrawMesh();
		Mesh();
		~Mesh();
			
		
};

#endif