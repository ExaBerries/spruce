#version 330
in vec3 position;
uniform vec4 color;
out vec4 fragColor;

void main() {
	vec3 normal = normalize(position);
	float intensity = dot(normal, normalize(vec3(1, 1, 1)));
	intensity = 1;
	fragColor = vec4(color.rgb * intensity, color.a);
}