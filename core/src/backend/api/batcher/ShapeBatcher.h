#pragma once
#include <backend/api/batcher/Batcher.h>

namespace spruce {
	class ShapeBatcher : public Batcher {
		public:
			enum ShapeBatcherMode {
				RECT, LINE
			};
			ShapeBatcherMode mode;
			mat4f camera;

			ShapeBatcher(buffer<VertexAttribute> shaderAttributes, Shader* shader);
			virtual ~ShapeBatcher();

			void render();
			void batch(buffer<float> vertices, buffer<uint16> indices, ShapeBatcherMode mode, mat4f camera);
	};
}
