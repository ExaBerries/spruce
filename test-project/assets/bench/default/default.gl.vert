#version 330
in vec3 position;
uniform mat4 worldTrans;
uniform mat4 camera;
uniform mat4 shadowCamera;
out vec4 shadowPos;

void main() {
	gl_Position = camera * worldTrans * vec4(position, 1.0);
	shadowPos = shadowCamera * worldTrans * vec4(position, 1.0);
}