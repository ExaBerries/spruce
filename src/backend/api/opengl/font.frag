R"***(
#version 330
in vec2 coord;
uniform sampler2D tex;
uniform vec4 color;
out vec4 fragColor;
void main() {
	fragColor = vec4(1, 1, 1, texture(tex, coord)) * color;
}
)***"