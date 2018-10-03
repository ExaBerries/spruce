#include <backend/api/batcher/FontBatcher.h>
#include <app.h>

namespace spruce {
	FontBatcher::FontBatcher(buffer<VertexAttribute> shaderAttributes, Shader* shader) : Batcher(shaderAttributes, shader, 240, 0) {
	}

	FontBatcher::~FontBatcher() {
	}

	void FontBatcher::render() {
		if (font == nullptr || verticesIndex == 0) {
			return;
		}
		app::api->bind(shader);
		app::api->setUniform(shader, "camera", camera);
		app::api->setUniform(shader, "color",  color);
		app::api->bind(font->texture);
		app::api->setUniform(shader, "tex", font->texture);
		app::api->render(buffer<float>(verticesIndex, vertices), buffer<uint16>(indicesIndex, indices), shader, graphics::TRIANGLE);
	}

	void FontBatcher::batch(buffer<float> vertices, Font& font, spruce::color color, mat4f camera) {
		if (this->font != nullptr && (this->font != &font || this->color != color || this->camera != camera)) {
			flush();
		}
		this->font = &font;
		this->color = color;
		this->camera = camera;
		addVertices(vertices);
	}
}
