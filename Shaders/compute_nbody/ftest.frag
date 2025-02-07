#version 430
out vec4 color;

in vec4 fragColor;

uniform sampler2D samplerColorMap;
uniform sampler2D samplerGradientRamp;

void main() {
    color = vec4(fragColor.rgb, 1.0); // 白色粒子
}