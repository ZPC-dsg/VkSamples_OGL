#version 430

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

layout (std140, binding = 0) uniform UBO
{
    vec4 color;
    vec2 bias;
} ubo;

out vec4 fragColor;
out vec2 fragBias;

void main ()
{
    gl_Position = vec4(aPos, 1.0);
    fragColor = ubo.color;
    fragBias = ubo.bias;
}