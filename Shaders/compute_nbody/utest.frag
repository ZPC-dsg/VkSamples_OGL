#version 430

in vec4 fragColor;
in vec2 fragBias;

out vec4 color;

void main ()
{
    color = vec4(fragColor.rgb, 1.0);
}