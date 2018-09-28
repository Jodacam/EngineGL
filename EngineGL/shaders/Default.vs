#version 420 core

in vec3 inPos;	
in vec3 inColor;
in vec2 inTexCoord;
in vec3 inNormal;

uniform mat4 modelViewProj;
uniform mat4 modelView;
uniform mat4 normalMatrix;

struct DirLight {
    vec3 Dir;
    vec3 Color;
    vec3 CameraDir;
};

layout(shared) uniform DirectionalLights{
 	DirLight DLight[2];
};

out vec3 incolor;
out vec3 pos;
out vec3 norm;
out vec2 texCoord;




void main()
{
	incolor = inColor;
	texCoord = inTexCoord;
	norm = (normalMatrix * vec4(inNormal, 0.0)).xyz;
	pos = (modelView * vec4(inPos, 1.0)).xyz;
	gl_Position =  modelViewProj * vec4 (inPos,1.0);
}