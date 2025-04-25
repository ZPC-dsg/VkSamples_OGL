#version 450

out vec4 color;

in vec2 texCoord;

uniform sampler2D girl;

void main ()
{
    color = vec4(texture(girl, texCoord).rgb, 1.0);
}