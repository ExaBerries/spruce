#version 450
#extension GL_ARB_separate_shader_objects : enable
layout(location=0) in vec3 position;
layout(binding=1) uniform trans {
	mat4 worldTrans;
	mat4 camera;
	mat4 shadowCamera;
};
layout(location=0) out vec4 shadowPos;

void main() {
	gl_Position = camera * worldTrans * vec4(position, 1.0);
	shadowPos = shadowCamera * worldTrans * vec4(position, 1.0);
}