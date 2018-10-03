#include <backend/api/RenderAPI.h>
#include <common.h>

namespace spruce {
	RenderAPI::RenderAPI(Window* window, vec3f ndcSize) {
		this->window = window;
		this->ndcSize = ndcSize;
		this->fontBatcher = nullptr;
		this->shapeBatcher = nullptr;
	}

	RenderAPI::~RenderAPI() {
		delete fontBatcher;
		delete shapeBatcher;
	}

	void RenderAPI::render(string str, Font& font, spruce::color color, vec3f position, quaternion rotation, vec2f size, mat4f camera) {
		if (font.texture == nullptr || font.texture->width == 0 || font.texture->height == 0) {
			return;
		}
		if (fontBatcher == nullptr) {
			return;
		}
		float x = 0;
		float y = 0;
		struct FontVertex {
			vec3f position;
			vec2f coord;
		};
		buffer<FontVertex> coords(6 * str.size());
		int n = 0;
		for (uint32 i = 0; i < str.size(); i++) {
			char p = str.c_str()[i];
			if (p < 0) {
				continue;
			}
			float x2 = x + font.chars[p].bl * size.x / font.size;
			float y2 = -y - font.chars[p].bt * size.y / font.size;
			float w = font.chars[p].bw * size.x / font.size;
			float h = font.chars[p].bh * size.y / font.size;
			if (p == '\n') {
				y -= h + 0.02;
				x = 0;
				continue;
			}
			x += font.chars[p].ax * size.x / font.size;
			y += font.chars[p].ay * size.y / font.size;
			if (w == 0 || h == 0) {
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
		for (uint32 i = n; i < coords.size; i++) {
			coords[i].position = vec3f(0, 0, 0);
			coords[i].coord = vec2f(0, 0);
		}
		fontBatcher->batch((buffer<float>) coords, font, color, camera);
		fontBatcher->flush();
		coords.free();
	}

	void RenderAPI::renderLine(vec3f a, vec3f b, color colora, color colorb, mat4f camera) {
		if (shapeBatcher == nullptr) {
			return;
		}
		buffer<float> shapeVertices(14);
		buffer<uint16> shapeIndices(2);
		uint16 i = 0;
		uint16 lineVertexCount = 0;
		shapeVertices[lineVertexCount++] = a.x;
		shapeVertices[lineVertexCount++] = a.y;
		shapeVertices[lineVertexCount++] = a.z;
		shapeVertices[lineVertexCount++] = colora.r;
		shapeVertices[lineVertexCount++] = colora.g;
		shapeVertices[lineVertexCount++] = colora.b;
		shapeVertices[lineVertexCount++] = colora.a;
		shapeIndices[i++] = 0;
		shapeVertices[lineVertexCount++] = b.x;
		shapeVertices[lineVertexCount++] = b.y;
		shapeVertices[lineVertexCount++] = b.z;
		shapeVertices[lineVertexCount++] = colorb.r;
		shapeVertices[lineVertexCount++] = colorb.g;
		shapeVertices[lineVertexCount++] = colorb.b;
		shapeVertices[lineVertexCount++] = colorb.a;
		shapeIndices[i++] = 1;
		shapeBatcher->batch((buffer<float>) shapeVertices, shapeIndices, ShapeBatcher::LINE, camera);
		shapeBatcher->flush();
		shapeVertices.free();
		shapeIndices.free();
	}

	void RenderAPI::renderRect(vec3f pos, vec2f size, color color, quaternion rotation, mat4f camera) {
		if (shapeBatcher == nullptr) {
			return;
		}
		struct ShapeVertex {
			vec3f position;
			spruce::color color;
		};
		buffer<ShapeVertex> shapeVertices(4);
		buffer<uint16> shapeIndices(6);
		vec3f halfSize = vec3f(size, 0) / 2;
		shapeVertices[0].position = pos - (halfSize * rotation);
		shapeVertices[0].color = color;
		shapeVertices[1].position = pos + (vec3f(halfSize.x, -halfSize.y, 0) * rotation);
		shapeVertices[1].color = color;
		shapeVertices[2].position = pos + (vec3f(-halfSize.x, halfSize.y, 0) * rotation);
		shapeVertices[2].color = color;
		shapeVertices[3].position = pos + (halfSize * rotation);
		shapeVertices[3].color = color;
		shapeIndices[0] = 0;
		shapeIndices[1] = 1;
		shapeIndices[2] = 2;
		shapeIndices[3] = 2;
		shapeIndices[4] = 1;
		shapeIndices[5] = 3;
		shapeBatcher->batch((buffer<float>) shapeVertices, shapeIndices, ShapeBatcher::RECT, camera);
		shapeBatcher->flush();
		shapeVertices.free();
		shapeIndices.free();
	}
}
