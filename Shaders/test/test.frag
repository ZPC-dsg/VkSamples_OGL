#version 450

out vec4 color;

struct ColorBlock {
    vec3 colors;
    float intensity[3];
};

uniform ColorBlock block;
uniform float time;

void main ()
{
    color = vec4(vec3(block.colors.r * block.intensity[0], block.colors.g * block.intensity[1], 
    block.colors.b * block.intensity[2]) * time, 1.0);
}