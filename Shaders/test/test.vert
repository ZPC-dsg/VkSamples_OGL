#version 450
#extension GL_NV_uniform_buffer_std430_layout : enable

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

layout (binding = 0, std430) uniform MVP_Uniform
{
    mat4 MVP;
};

void main ()
{
    gl_Position = MVP * vec4(aPos, 1.0);
}
