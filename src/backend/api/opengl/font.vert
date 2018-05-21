R"***(
#version 330
in vec3 position;
in vec2 texCoord;
uniform mat4 camera;
out vec2 coord;

void main() {
	gl_Position = camera * vec4(position, 1);
	coord = texCoord;
}
)***"