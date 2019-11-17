#version 450
#extension GL_ARB_separate_shader_objects : enable
layout(location=0) in vec4 shadowPos;
layout(binding=1) uniform sampler2D shadowMap;
layout(binding=2) uniform colorBlock {
	vec4 color;
};
layout(location=0) out vec4 fragColor;

void main() {
	float intensity = 1.0;
	vec2 texPos = shadowPos.xy;
	if (texPos.x >= 0 && texPos.x <= 1 && texPos.y >= 0 && texPos.y <= 1) {
		intensity = (texture(shadowMap, shadowPos.xy).r < shadowPos.z - 0.001) ? 0.5 : 1.0;
	} else {
		intensity = 1.0;
	}
	fragColor = vec4(color.rgb * intensity, color.a);
}