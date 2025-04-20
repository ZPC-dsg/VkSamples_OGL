#version 450

out vec4 color;

in vec2 texCoord;

void main ()
{
    color = vec4(texCoord, 1.0, 1.0);
}