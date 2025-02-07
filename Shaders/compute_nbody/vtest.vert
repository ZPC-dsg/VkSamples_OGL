#version 430
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

out vec4 fragColor;

layout (std140, binding = 2) uniform UBO 
{
	mat4 projection;
	mat4 modelview;
	vec2 screendim;
} ubo;

void main() {
    gl_Position = vec4(position.xyz, 1.0);
    gl_PointSize = 20.0; // 设置粒子大小

    fragColor = color;
}