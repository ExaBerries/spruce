#version 330
in vec2 uv;
uniform sampler2D tex;
uniform vec2 res;
out vec4 fragColor;

void main() {
	float x = 1.0 / res.x;
	float y = 1.0 / res.y;
	vec4 edgeh = vec4(0.0);
	edgeh -= texture(tex, vec2(uv.x - x, uv.y - y));
	edgeh -= texture(tex, vec2(uv.x - x, uv.y)) * 2.0;
	edgeh -= texture(tex, vec2(uv.x - x, uv.y + y));
	edgeh += texture(tex, vec2(uv.x + x, uv.y - y));
	edgeh += texture(tex, vec2(uv.x + x, uv.y + y)) * 2.0;
	edgeh += texture(tex, vec2(uv.x + x, uv.y + y));
	vec4 edgev = vec4(0.0);
	edgev -= texture(tex, vec2(uv.x - x, uv.y - y));
	edgev -= texture(tex, vec2(uv.x, uv.y - y)) * 2.0;
	edgev -= texture(tex, vec2(uv.x + x, uv.y - y));
	edgev += texture(tex, vec2(uv.x - x, uv.y + y));
	edgev += texture(tex, vec2(uv.x, uv.y + y)) * 2.0;
	edgev += texture(tex, vec2(uv.x + x, uv.y + y));
	vec3 edge = sqrt((edgeh.rgb * edgeh.rgb) + (edgev.rgb * edgev.rgb));
	vec4 sobel = vec4(edge, texture(tex, uv).a);
	fragColor = texture(tex, uv);// + sobel;
}