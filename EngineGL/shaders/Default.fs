#version 420 core
uniform mat4 modelViewProj;
uniform mat4 modelView;
uniform mat4 normalMatrix;

struct DirLight {
    vec3 Dir;
    vec3 Color;
    vec3 CameraDir;
};


layout(shared) uniform DirectionalLights {
   DirLight DLight[2];
};

in vec3 incolor;
in vec3 pos;
in vec3 norm;
in vec2 texCoord;

out vec4 outColor;
void main()
{   
    vec3 normal = normalize(norm);
    vec3 LNormal = normalize(DLight[0].CameraDir);
    vec3 ambientColor=vec3(0.25,0.25,0.25);
    vec3 diffuseColor =DLight[0].Color*max(dot(LNormal,normal),0.0);
    vec3 finalcolor = (ambientColor+diffuseColor)*incolor;

	outColor = vec4(finalcolor,1);
}