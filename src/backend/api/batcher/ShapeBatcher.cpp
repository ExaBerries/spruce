#include <backend/api/batcher/ShapeBatcher.h>
#include <app/app.h>

namespace spruce {
	ShapeBatcher::ShapeBatcher(buffer<VertexAttribute> shaderAttributes, Shader* shader) : Batcher(shaderAttributes, shader, 240, 120) {
	}

	ShapeBatcher::~ShapeBatcher() {
	}

	void ShapeBatcher::render() {
		if (verticesIndex == 0) {
			return;
		}
		if (mode == LINE) {
			app::api->bind(shader);
			app::api->setUniform(shader, "camera", camera);
			app::api->render(buffer<float>(verticesIndex, vertices), buffer<uint16>(indicesIndex, indices), shader, graphics::LINE);
		} else if (mode == RECT) {
			app::api->bind(shader);
			app::api->setUniform(shader, "camera", camera);
			app::api->render(buffer<float>(verticesIndex, vertices), buffer<uint16>(indicesIndex, indices), shader, graphics::TRIANGLE);
		}
	}

	void ShapeBatcher::batch(buffer<float> vertices, buffer<uint16> indices, ShapeBatcherMode mode, mat4f camera) {
		if (this->mode != mode || this->camera != camera) {
			flush();
		}
		this->mode = mode;
		this->camera = camera;
		addVertices(vertices);
		addIndices(indices);
	}
}
