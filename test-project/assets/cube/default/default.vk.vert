#version 450
#extension GL_ARB_separate_shader_objects : enable
layout(location=0) in vec3 position;
layout(binding=0) uniform trans {
	mat4 worldTrans;
	uniform mat4 camera;
	uniform mat4 shadowCamera;
};
out gl_PerVertex {
	vec4 gl_Position;
};
layout(location=0) out vec4 shadowPos;

void main() {
	gl_Position = camera * worldTrans * vec4(position, 1.0);
	shadowPos = shadowCamera * worldTrans * vec4(position, 1.0);
}