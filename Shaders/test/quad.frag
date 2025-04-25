#version 450

out vec4 color;

in vec2 texCoord;

uniform sampler2D quad_image;

void main() {
    color = vec4(texture(quad_image, texCoord).rgb, 1.0);
}