#include <backend/api/RenderAPI.h>
#include <common.h>

namespace spruce {
	RenderAPI::RenderAPI(Window* window, vec3f ndcSize) {
		this->window = window;
		this->ndcSize = ndcSize;
		this->fontAttributes = nullptr;
		this->fontShader = nullptr;
		this->fontMesh = nullptr;
	}

	RenderAPI::~RenderAPI() {
		if (fontAttributes != nullptr) {
			delete[] fontAttributes;
		}
		if (fontShader != nullptr) {
			delete fontShader;
		}
		if (fontMesh != nullptr) {
			fontMesh->vertices = nullptr;
			fontMesh->indices = nullptr;
			delete fontMesh;
		}
	}

	void RenderAPI::render(string str, Font& font, spruce::color color, vec3f position, quaternion rotation, vec2f size, mat4f camera) {
		if (font.texture == nullptr || font.texture->width == 0 || font.texture->height == 0) {
			return;
		}
		if (fontShader == nullptr || fontMesh == nullptr) {
			return;
		}
		setBlend(true);
		if (fontMesh->vertices != nullptr) {
			delete[] (FontVertex*)(fontMesh->vertices);
			fontMesh->vertices = nullptr;
		}
		float x = 0;
		float y = 0;
		FontVertex* coords = new FontVertex[6 * str.size()];
		int n = 0;
		for (uint32 i = 0; i < str.size(); i++) {
			char p = str.c_str()[i];
			if (p < 0) {
				continue;
			}
			float x2 = x + font.chars[p].bl * size.x;
			float y2 = -y - font.chars[p].bt * size.y;
			float w = font.chars[p].bw * size.x;
			float h = font.chars[p].bh * size.y;
			x += font.chars[p].ax * size.x;
			y += font.chars[p].ay * size.y;
			if (!w || !h) {
				continue;
			}
			coords[n].position = position + vec3f(x2, -y2, 0) * rotation;
			coords[n].coord = vec2f(font.chars[p].tx, 0);
			n++;
			coords[n].position = position + vec3f(x2 + w, -y2, 0) * rotation;
			coords[n].coord = vec2f(font.chars[p].tx + font.chars[p].bw / font.texture->width, 0);
			n++;
			coords[n].position = position + vec3f(x2, -y2 - h, 0) * rotation;
			coords[n].coord = vec2f(font.chars[p].tx, font.chars[p].bh / font.texture->height);
			n++;
			coords[n].position = position + vec3f(x2 + w, -y2, 0) * rotation;
			coords[n].coord = vec2f(font.chars[p].tx + font.chars[p].bw / font.texture->width, 0);
			n++;
			coords[n].position = position + vec3f(x2, -y2 - h, 0) * rotation;
			coords[n].coord = vec2f(font.chars[p].tx, font.chars[p].bh / font.texture->height);
			n++;
			coords[n].position = position + vec3f(x2 + w, -y2 - h, 0) * rotation;
			coords[n].coord = vec2f(font.chars[p].tx + font.chars[p].bw / font.texture->width, font.chars[p].bh / font.texture->height);
			n++;
		}
		bind(fontShader);
		setUniform(fontShader, "camera", Shader::VERTEX, camera);
		setUniform(fontShader, "color", Shader::FRAGMENT, color);
		bind(font.texture);
		setUniform(fontShader, "tex", Shader::FRAGMENT, font.texture);
		fontMesh->vertices = (float*) coords;
		fontMesh->vertexCount = 6 * str.size() * sizeof(FontVertex) / sizeof(float);
		fontMesh->toVRAM(fontShader);
		render(fontMesh, fontShader);
	}
}
