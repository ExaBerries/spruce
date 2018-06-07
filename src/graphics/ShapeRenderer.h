#pragma once
#include <common.h>
#include <math/mat4f.h>
#include <graphics/Mesh.h>
#include <graphics/color.h>

namespace spruce {
	class ShapeRenderer {
		public:
			mat4f* camera;

			ShapeRenderer();
			ShapeRenderer(const ShapeRenderer& shapeRenderer) = delete;
			virtual ~ShapeRenderer();

			virtual void begin(Camera& camera) = 0;
			virtual void end() = 0;
			virtual void line(vec3f a, vec3f b, color colora, color colorb) = 0;
			virtual void rect(vec2f pos, vec2f size, color color) = 0;
	};
}
