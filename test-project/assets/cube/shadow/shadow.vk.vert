#version 450
layout(location=0) in vec3 position;
layout(binding=0) uniform trans {
	mat4 worldTrans;
	mat4 camera;
};

void main() {
	gl_Position = camera * worldTrans * vec4(position, 1.0);
}