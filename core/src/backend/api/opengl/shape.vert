R"***(
#version 330
in vec3 a_pos;
in vec4 a_color;
uniform mat4 camera;
out vec4 color;

void main() {
	color = a_color;
	gl_Position = camera * vec4(a_pos, 1.0);
}
)***"