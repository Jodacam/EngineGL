#version 420 core
uniform mat4 modelViewProj;
uniform mat4 modelView;
uniform mat4 normalMatrix;

layout(shared) uniform DirLight{
    vec3 color;
    vec3 LocalDirrection;
    vec3 CameraDirrection;
};

in vec3 incolor;
in vec3 pos;
in vec3 norm;
in vec2 texCoord;

out vec4 outColor;
void main()
{   
	outColor = vec4(1,0,0,1);
}