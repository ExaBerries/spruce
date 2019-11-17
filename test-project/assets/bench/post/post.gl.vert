#version 330
in vec3 position;
in vec2 a_uv;
out vec2 uv;

void main() {
	gl_Position = vec4(position, 1.0);
	uv = a_uv;
}