#pragma once
#include <common.h>
#include <graphics/ShapeRenderer.h>

namespace spruce {
	class MetalShapeRenderer : public ShapeRenderer {
		public:
			MetalShapeRenderer();
			~MetalShapeRenderer();

			void begin(Camera& camera);
			void end();
			void line(vec3f a, vec3f b, color colora, color colorb);
			void rect(vec2f pos, vec2f size, color color);
	};
}
