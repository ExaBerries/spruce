#version 330
in vec3 position;
uniform mat4 worldTrans;
uniform mat4 camera;

void main() {
	gl_Position = camera * worldTrans * vec4(position, 1.0);
}