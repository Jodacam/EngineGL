#pragma once
#ifndef MATERIAL_H_
#define MATERIAL_H_
#include <vector>
#include <map>
#include "auxiliar.h"
#include "Shader.h"
using namespace std;
enum  MaterialTypes
{
	DEFAULT,
	DEFAULT_DIFFUSE,
	DEFAULT_PBR,
	DEFAULT_UNLIT
};


class Material {
	private:
		vector<string> split(const string& str, const string& delim)
		{
			vector<string> tokens;
			size_t prev = 0, pos = 0;
			do
			{
				pos = str.find(delim, prev);
				if (pos == string::npos) pos = str.length();
				string token = str.substr(prev, pos - prev);
				if (!token.empty()) tokens.push_back(token);
				prev = pos + delim.length();
			} while (pos < str.length() && prev < str.length());
			return tokens;
		}


		Shader* shader;
		
		std::map<std::string, int> uniforms;
		std::map<std::string, int> samplers;
		map<string, float> floats;
		map<string, glm::mat4> matrix4;
		map<string, glm::vec3> vector3;
		map<string, glm::vec4> vector4;
		map<string, glm::mat3> matrix3;
		map<string, int> integer;


		unsigned int loadText(const char* fileName);
	public:
		Material(const char* ShaderPath);
		void SetTexture(const char* name, const char* fileName);
		float SetFloat(const char* name, float value);
		int SetInt(const char* name, int value);
		void SetMatrix(const char* name, glm::mat4 value);
		void SetVector(const char* name, glm::vec2 value);
		void SetVector(const char* name, glm::vec3 value);
		void SetVector(const char* name, glm::vec4 value);
		void SetMatrix(const char* name, glm::mat3 value);
		static Material* CreateMaterialOfType(MaterialTypes type);
		void BlindTextures();
		Shader* getShader() { return shader; };
		Material(Shader* s);
};
#endif