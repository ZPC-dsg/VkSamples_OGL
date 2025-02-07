#version 450

uniform sampler2D samplerColorMap;
uniform sampler2D samplerGradientRamp;

layout (location = 0) in float outGradientPos;

layout (location = 0) out vec4 outFragColor;

void main () 
{
	vec3 color = texture(samplerGradientRamp, vec2(outGradientPos, 0.0)).rgb;
	outFragColor.rgb = texture(samplerColorMap, gl_PointCoord).rgb * color * 5.0;
}
