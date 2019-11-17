#version 330
//in vec4 shadowPos;
//uniform sampler2D shadowMap;
uniform vec4 color;
layout(location=0) out vec4 fragColor;
layout(location=1) out vec4 bloomColor;

void main() {
	vec3 sun = vec3(1, 1, 0);
	float intensity = 1.0;
	//vec2 texPos = shadowPos.xy;
	//if (texPos.x >= 0 && texPos.x <= 1 && texPos.y >= 0 && texPos.y <= 1) {
	//	intensity = (texture(shadowMap, shadowPos.xy).r < shadowPos.z - 0.001) ? 0.5 : 1.0;
	//} else {
	//	intensity = 1.0;
	//}
	fragColor = vec4(color.rgb * intensity, color.a);
	bloomColor = color * intensity;
}