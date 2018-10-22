#include "stdafx.h"
#include "Mesh.h"

void Mesh::initMesh(const int NVertex, const float * VertexPos, const float * VertexColor, const float * VertexNormal, const float * VertexTexCoord, const int NTriangleIndex, const unsigned int * TriangleIndex, const float * VertexTang)
{
	NTindex = NTriangleIndex;
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	glGenBuffers(1, &posVBO);
	glBindBuffer(GL_ARRAY_BUFFER, posVBO);
	glBufferData(GL_ARRAY_BUFFER, NVertex * sizeof(float) * 3,
		VertexPos, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &colorVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
	glBufferData(GL_ARRAY_BUFFER, NVertex * sizeof(float) * 3,
		VertexColor, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &normalVBO);
	glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
	glBufferData(GL_ARRAY_BUFFER, NVertex * sizeof(float) * 3,
		VertexNormal, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);

	glGenBuffers(1, &texCoordVBO);
	glBindBuffer(GL_ARRAY_BUFFER, texCoordVBO);
	glBufferData(GL_ARRAY_BUFFER, NVertex * sizeof(float) * 2,
		VertexTexCoord, GL_STATIC_DRAW);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(3);


	glGenBuffers(1, &TangVBO);
	glBindBuffer(GL_ARRAY_BUFFER, TangVBO);
	glBufferData(GL_ARRAY_BUFFER, NVertex * sizeof(float) * 3,
		VertexTang, GL_STATIC_DRAW);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(4);



	glGenBuffers(1, &triangleIndexVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangleIndexVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		NTriangleIndex * sizeof(unsigned int) * 3, TriangleIndex,
		GL_STATIC_DRAW);



}

Mesh::Mesh(const char * fileName)
{
	scene = importer.ReadFile(fileName, aiProcessPreset_TargetRealtime_Fast);
	unsigned int miNumVertex = scene->mMeshes[0]->mNumVertices;
	unsigned int miNumFaces = scene->mMeshes[0]->mNumFaces;
	   std::vector<unsigned int> miVertexIndex(miNumVertex*3);
	   std::vector<float> miVertexPos(miNumVertex*3);
	   std::vector<float> miModelColor(miNumVertex * 3);
	   std::vector<float> miNormals(miNumVertex * 3);
	   std::vector<float> miTexCoord(miNumVertex * 2);
	   std::vector<float> miVertexTang(miNumVertex * 3);
	   std::cout << miNumFaces << " " << miNumVertex << std::endl;


	int aux = 0;
	for (int i = 0; i < miNumVertex; i++) {
		for (int j = 0; j < 3; j++) {
			miVertexPos[aux] = scene->mMeshes[0]->mVertices[i][j];
			aux++;
		}
	}

	aux = 0;
	for (int i = 0; i < miNumFaces; i++) {
		for (int j = 0; j < 3; j++) {
			miVertexIndex[aux] = scene->mMeshes[0]->mFaces[i].mIndices[j];
			aux++;
		}
	}
	aux = 0;
	for (int i = 0; i < miNumVertex; i++) {
		miModelColor[aux] = 1;
		aux++;

		miModelColor[aux] = 0.411765;
		aux++;

		miModelColor[aux] = 0.705882;
		aux++;
	}

	aux = 0;
	for (int i = 0; i < miNumVertex; i++) {
		for (int j = 0; j < 3; j++) {
			miNormals[aux] = scene->mMeshes[0]->mNormals[i][j];
			aux++;
		}
	}

	aux = 0;
	if (scene->mMeshes[0]->HasTextureCoords(0)) {
		for (int i = 0; i < miNumVertex; i++) {
			for (int j = 0; j < 2; j++) {
				miTexCoord[aux] = scene->mMeshes[0]->mTextureCoords[0][i][j];
				aux++;
			}
		}
	}
	aux = 0;
	if (scene->mMeshes[0]->HasTangentsAndBitangents()) {
		for (int i = 0; i < miNumVertex; i++) {
			for (int j = 0; j < 3; j++) {
				miVertexTang[aux] = scene->mMeshes[0]->mTangents[i][j];
				aux++;
			}
		}
	}
	miVertexIndex2	= miVertexIndex;
	miVertexPos2 = miVertexPos;
	miModelColor2 = miModelColor;
	miNormals2 = miNormals;
	miTexCoord2 = miTexCoord;
	miVertexTang2 = miVertexTang;
	initMesh(miNumVertex, &miVertexPos[0], &miModelColor[0],&miNormals[0], &miTexCoord[0], miNumFaces, &miVertexIndex[0], &miVertexTang[0]);
}

void Mesh::DrawMesh()
{
	glBindVertexArray(vaoID);
	glDrawElements(GL_TRIANGLES, NTindex * 3,

		GL_UNSIGNED_INT, (void*)0);
}

Mesh::Mesh()
{

}

Mesh::~Mesh()
{

}
