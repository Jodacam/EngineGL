#include "stdafx.h"
#include "Material.h"
#include "json.hpp"
#include <fstream>
#include <sstream>

unsigned int Material::loadText(const char * fileName)
{
	unsigned char *map;
	unsigned int w, h;
	map = loadTexture(fileName, w, h);

	if (!map) {
		std::cout << "Error cargando el fichero: " << fileName << std::endl;
		return -1;
	}

	unsigned int texId;
	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_2D, texId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, (GLvoid*)map);
	delete[] map;

	glGenerateMipmap(GL_TEXTURE_2D);
	//Anisotrópico
	GLint num = 0;

	glGetIntegerv(GL_NUM_EXTENSIONS, &num);

	bool found = false;

	while (0<--num & !found) {
		if (strcmp(((char *)glGetStringi(GL_EXTENSIONS, num - 1)), "GL_EXT_texture_filter_anisotropic"))
			found = true;
		//std::cout << glGetStringi( GL_EXTENSIONS, num - 1 ) << std::endl; 
	}

	if (found) {
		GLfloat fLargest;
		glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &fLargest);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
		printf("App::Load > %.0fx Anistropic filtering supported.", fLargest);
	}
	else {
		printf("Anistropic filtering Not supported");
	}
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	return texId;
}

Material::Material(const char * ShaderPath)
{
	std::ifstream t("file.txt");
	std::stringstream buffer;
	buffer << t.rdbuf();
	string s = buffer.str();
	vector<string> lines = split(s, "#Properties");
	string propiedades = lines[1];
	

}

void Material::SetTexture(const char * name, const char * fileName)
{
	int uniformTextId = uniforms[name];
	if (uniformTextId != -1) {
		unsigned int identifier = loadText(fileName);
		samplers[name] = identifier;
	}
	else
	{
		printf("That Texture Don't Exist");
	}


}

float Material::SetFloat(const char * name, float value)
{

	float actualValue = floats[name];
	floats[name] = value;
	return actualValue;
}

int Material::SetInt(const char * name, int value)
{
	int actualValue = integer[name];
	integer[name] = value;
	return actualValue;
}

void Material::SetMatrix(const char * name, glm::mat4 value)
{

	int uniformid = uniforms[name];
	if (uniformid != -1) {
		glUniformMatrix4fv(uniformid, 1, GL_FALSE, &value[0][0]);
	}
	else {
		printf("Uniform value do not found");
	}

}

void Material::SetVector(const char * name, glm::vec2 value)
{

	int uniformid = uniforms[name];
	if (uniformid != -1) {
		glUniform2fv(uniformid, 1, &value[0]);
	}
	else {
		printf("Uniform value do not found");
	}
}

void Material::SetVector(const char * name, glm::vec3 value)
{
	int uniformid = uniforms[name];
	if (uniformid != -1) {
		glUniform3fv(uniformid, 1, &value[0]);
	}
	else {
		printf("Uniform value do not found");
	}
}

void Material::SetVector(const char * name, glm::vec4 value)
{
	int uniformid = uniforms[name];
	if (uniformid != -1) {
		glUniform4fv(uniformid, 1, &value[0]);
	}
	else {
		printf("Uniform value do not found");
	}
}

void Material::SetMatrix(const char * name, glm::mat3 value)
{
	int uniformid = uniforms[name];
	if (uniformid != -1) {
		glUniformMatrix4fv(uniformid, 1, GL_FALSE, &value[0][0]);
	}
	else {
		printf("Uniform value do not found");
	}
}

Material* Material::GetMaterialOfType(MaterialTypes type)
{
	Material* m = nullptr;
	switch (type)
	{
		
	case DEFAULT:
		break;
	case DEFAULT_DIFFUSE:
		break;
	case DEFAULT_PBR:
		break;
	case DEFAULT_UNLIT:
		break;
	default:
		break;
	}

	return m;
}

void Material::BlindTextures()
{
	int TextureId = 0;
	for (auto const &sampler : samplers) {
		glActiveTexture(GL_TEXTURE0 + TextureId);
		glBindTexture(GL_TEXTURE_2D, sampler.second);		
		shader->SetInt(sampler.first.c_str(), sampler.second);
		TextureId++;
	}

}

Material::Material(Shader * s)
{
	shader = s;
}
