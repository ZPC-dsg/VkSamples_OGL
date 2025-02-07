#version 450

out vec4 color;

in vec2 texCoord;

uniform sampler2D image;

void main ()
{
    color = vec4(texture(image, texCoord).rgb, 1.0);
}