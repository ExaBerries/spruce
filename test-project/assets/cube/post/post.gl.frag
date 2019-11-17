#version 330
in vec2 uv;
uniform sampler2D mainPass;
uniform sampler2D bloomPass;
uniform vec2 res;
out vec4 fragColor;

vec4 blur(sampler2D image, vec2 uv, vec2 resolution) {
	vec4 color = vec4(0.0);
	float weight = 1.0 / 36.0;
	for (int x = -6; x < 6; x++) {
		for (int y = -6; y < 6; y++) {
			color += texture(image, uv + vec2(x, y) / res) * weight;
		}
	}
	return color;
}

void main() {
	fragColor = texture(mainPass, uv) + blur(bloomPass, uv, res);
}