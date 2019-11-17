#version 330
in vec3 a_position;
uniform mat4 camera;
uniform mat4 worldTrans;
out vec3 position;

void main() {
	gl_Position = camera * worldTrans * vec4(a_position, 1.0);
	position = a_position;
}