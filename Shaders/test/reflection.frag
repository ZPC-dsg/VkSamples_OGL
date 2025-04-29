#version 450

out vec4 color;

layout (location = 0) in float x1;
layout (location = 1) in float x2;
layout (location = 2) in float x3;
layout (location = 3) in float x4;

void main() {
    float temp = x1 + x2 + x3 + x4 / 4.0;
    color = vec4(vec3(temp), 1.0);
}