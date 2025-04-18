#version 450

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexcoord;
layout (location = 3) in vec4 aTangent;

uniform mat4 MVP;

out vec2 texCoord;

void main ()
{
    gl_Position = MVP * vec4(aPos, 1.0);
    texCoord = aTexcoord;
}
