#include <backend/api/RenderAPI.h>
#include <common.h>

namespace spruce {
	RenderAPI::RenderAPI(Window* window, vec3f ndcSize) : fontAttributes(nullptr), fontVertices(nullptr), fontIndices(nullptr), shapeAttributes(nullptr) {
		this->window = window;
		this->ndcSize = ndcSize;
		this->fontShader = nullptr;
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
		if (fontVertices != nullptr) {
			fontVertices.free();
		}
		if (fontIndices != nullptr) {
			fontIndices.free();
		}
		if (shapeAttributes != nullptr) {
			shapeAttributes.free();
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
		if (fontShader == nullptr) {
			return;
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
			if (p == '\n') {
				y -= h + 0.02;
				x = 0;
				continue;
			}
			x += font.chars[p].ax * size.x;
			y += font.chars[p].ay * size.y;
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
		bind(fontShader);
		setUniform(fontShader, "camera", camera);
		setUniform(fontShader, "color",  color);
		bind(font.texture);
		setUniform(fontShader, "tex", font.texture);
		fontVertices = (buffer<float>) coords;
		fontIndices = nullptr;
		render(fontVertices, fontIndices, fontShader, graphics::TRIANGLE);
		coords.free();
		fontVertices = nullptr;
	}

	void RenderAPI::renderLine(vec3f a, vec3f b, color colora, color colorb, mat4f camera) {
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
		setUniform(shapeShader, "camera", camera);
		render(shapeMesh, shapeShader, graphics::LINE);
	}

	void RenderAPI::renderRect(vec3f pos, vec2f size, color color, quaternion rotation, mat4f camera) {
		if (shapeShader == nullptr || shapeMesh == nullptr) {
			return;
		}
		shapeMesh->vertices.free();
		shapeMesh->indices.free();
		struct ShapeVertex {
			vec3f position;
			spruce::color color;
		};
		buffer<ShapeVertex> vertices(4);
		buffer<uint16> indices(6);
		vec3f halfSize = vec3f(size, 0) / 2;
		vertices[0].position = pos - (halfSize * rotation);
		vertices[0].color = color;
		vertices[1].position = pos + (vec3f(halfSize.x, -halfSize.y, 0) * rotation);
		vertices[1].color = color;
		vertices[2].position = pos + (vec3f(-halfSize.x, halfSize.y, 0) * rotation);
		vertices[2].color = color;
		vertices[3].position = pos + (halfSize * rotation);
		vertices[3].color = color;
		indices[0] = 0;
		indices[1] = 1;
		indices[2] = 2;
		indices[3] = 2;
		indices[4] = 1;
		indices[5] = 3;
		shapeMesh->vertices = (buffer<float>) vertices;
		shapeMesh->indices = indices;
		shapeMesh->toVRAM(shapeShader);
		bind(shapeShader);
		setUniform(shapeShader, "camera", camera);
		render(shapeMesh, shapeShader, graphics::TRIANGLE);
	}
}
