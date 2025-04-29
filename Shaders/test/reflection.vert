#version 450
#extension GL_NV_uniform_buffer_std430_layout : enable

layout (location = 0) in vec3 aPos;

struct fStruct {
    float x;
};

struct TestStruct {
    int ia;
    vec2 vb;
    mat4 mc;
    float ft;
    fStruct fd[2][2];
};

layout (std430, binding = 0) uniform TestBlock {
    TestStruct ts[2];

    int iarray[2][2][2];
};

layout (location = 0) out float x1;
layout (location = 1) out float x2;
layout (location = 2) out float x3;
layout (location = 3) out float x4;

void main() {
    gl_Position = vec4(aPos, 1.0);
    
    int a =ts[0].ia;
    vec2 b = ts[0].vb;
    mat4 c =ts[0].mc;
    float d1,d2,d3,d4;

    d1 = ts[0].fd[0][0].x;
    d2 = ts[0].fd[0][1].x + 1;
    x1 = ts[0].fd[0][1].x;
    d3 = ts[0].fd[1][0].x;
    d4 = ts[0].fd[1][1].x + 1;
    x2 = ts[0].fd[1][1].x;

    a = ts[1].ia;
    b = ts[1].vb;
    c = ts[1].mc;
    d1 = ts[1].fd[0][0].x;
    d2 = ts[1].fd[0][1].x + 1;
    x3 = ts[1].fd[0][1].x;
    d3 = ts[1].fd[1][0].x;
    d4 = ts[1].fd[1][1].x + 1;
    x4 = ts[1].fd[1][1].x;

    float d5 = ts[0].ft;
    float d6 = ts[0].ft;

    int testia [2][2][2] = iarray;
}