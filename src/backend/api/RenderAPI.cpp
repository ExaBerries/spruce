#include <backend/api/RenderAPI.h>
#include <common.h>

namespace spruce {
	RenderAPI::RenderAPI(Window* window, vec3f ndcSize) : fontAttributes(nullptr), shapeAttributes(nullptr) {
		this->window = window;
		this->ndcSize = ndcSize;
		this->fontShader = nullptr;
		this->fontMesh = nullptr;
		this->shapeShader = nullptr;
		this->shapeMesh = nullptr;
	}

	RenderAPI::~RenderAPI() {
		if (fontAttributes != nullptr) {
			fontAttributes.free();
		}
		if (fontShader != nullptr) {
			delete fontShader;
		}
		if (fontMesh != nullptr) {
			delete fontMesh;
		}
		if (shapeAttributes != nullptr) {
			fontAttributes.free();
		}
		if (shapeShader != nullptr) {
			delete shapeShader;
		}
		if (shapeMesh != nullptr) {
			delete shapeMesh;
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
			fontMesh->vertices.free();
			fontMesh->vertices = nullptr;
		}
		float x = 0;
		float y = 0;
		buffer<FontVertex> coords(6 * str.size());
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
		setUniform(fontShader, "camera", camera);
		setUniform(fontShader, "color",  color);
		bind(font.texture);
		setUniform(fontShader, "tex", font.texture);
		fontMesh->vertices = (buffer<float>) coords;
		fontMesh->toVRAM(fontShader);
		render(fontMesh, fontShader, graphics::TRIANGLE);
	}

	void RenderAPI::renderLine(vec3f a, vec3f b, color colora, color colorb) {
		if (shapeShader == nullptr || shapeMesh == nullptr) {
			return;
		}
		shapeMesh->vertices.free();
		shapeMesh->indices.free();
		buffer<float> vertices(14);
		buffer<uint16> indices(2);
		uint16 i = 0;
		uint16 lineVertexCount = 0;
		vertices[lineVertexCount++] = a.x;
		vertices[lineVertexCount++] = a.y;
		vertices[lineVertexCount++] = a.z;
		vertices[lineVertexCount++] = colora.r;
		vertices[lineVertexCount++] = colora.g;
		vertices[lineVertexCount++] = colora.b;
		vertices[lineVertexCount++] = colora.a;
		indices[i++] = 0;
		vertices[lineVertexCount++] = b.x;
		vertices[lineVertexCount++] = b.y;
		vertices[lineVertexCount++] = b.z;
		vertices[lineVertexCount++] = colorb.r;
		vertices[lineVertexCount++] = colorb.g;
		vertices[lineVertexCount++] = colorb.b;
		vertices[lineVertexCount++] = colorb.a;
		indices[i++] = 1;
		shapeMesh->vertices = vertices;
		shapeMesh->indices = indices;
		shapeMesh->toVRAM(shapeShader);
		bind(shapeShader);
		setUniform(shapeShader, "camera", mat4f());
		render(shapeMesh, shapeShader, graphics::LINE);
	}

	void RenderAPI::renderRect(vec2f pos, vec2f size, color color) {
		if (shapeShader == nullptr || shapeMesh == nullptr) {
			return;
		}
		shapeMesh->vertices.free();
		shapeMesh->indices.free();
		buffer<float> vertices(28);
		buffer<uint16> indices(6);
		vec2f halfSize = size / 2;
		uint16 filledVertexCount = 0;
		uint16 filledIndexCount = 0;
		vertices[filledVertexCount++] = pos.x - halfSize.x;
		vertices[filledVertexCount++] = pos.y - halfSize.y;
		vertices[filledVertexCount++] = 0;
		vertices[filledVertexCount++] = color.r;
		vertices[filledVertexCount++] = color.g;
		vertices[filledVertexCount++] = color.b;
		vertices[filledVertexCount++] = color.a;
		vertices[filledVertexCount++] = pos.x + halfSize.x;
		vertices[filledVertexCount++] = pos.y - halfSize.y;
		vertices[filledVertexCount++] = 0;
		vertices[filledVertexCount++] = color.r;
		vertices[filledVertexCount++] = color.g;
		vertices[filledVertexCount++] = color.b;
		vertices[filledVertexCount++] = color.a;
		vertices[filledVertexCount++] = pos.x - halfSize.x;
		vertices[filledVertexCount++] = pos.y + halfSize.y;
		vertices[filledVertexCount++] = 0;
		vertices[filledVertexCount++] = color.r;
		vertices[filledVertexCount++] = color.g;
		vertices[filledVertexCount++] = color.b;
		vertices[filledVertexCount++] = color.a;
		vertices[filledVertexCount++] = pos.x + halfSize.x;
		vertices[filledVertexCount++] = pos.y + halfSize.y;
		vertices[filledVertexCount++] = 0;
		vertices[filledVertexCount++] = color.r;
		vertices[filledVertexCount++] = color.g;
		vertices[filledVertexCount++] = color.b;
		vertices[filledVertexCount++] = color.a;
		indices[filledIndexCount++] = 0;
		indices[filledIndexCount++] = 1;
		indices[filledIndexCount++] = 2;
		indices[filledIndexCount++] = 2;
		indices[filledIndexCount++] = 1;
		indices[filledIndexCount++] = 3;
		shapeMesh->vertices = vertices;
		shapeMesh->indices = indices;
		shapeMesh->toVRAM(shapeShader);
		bind(shapeShader);
		setUniform(shapeShader, "camera", mat4f());
		render(shapeMesh, shapeShader, graphics::TRIANGLE);
	}
}
