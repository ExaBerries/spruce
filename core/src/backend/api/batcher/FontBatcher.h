#pragma once
#include <backend/api/batcher/Batcher.h>
#include <graphics/Font.h>

namespace spruce {
	class FontBatcher : public Batcher {
		public:
			Font* font;
			spruce::color color;
			vec3f position;
			quaternion rotation;
			vec2f size;
			mat4f camera;

			FontBatcher(buffer<VertexAttribute> shaderAttributes, Shader* shader);
			virtual ~FontBatcher();

			void render();
			void batch(buffer<float> vertices, Font& font, spruce::color color, mat4f camera);
	};
}
