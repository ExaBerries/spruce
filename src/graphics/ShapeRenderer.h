#pragma once
#include <common.h>
#include <math/mat4f.h>
#include <graphics/Mesh.h>

namespace spruce {
	class ShapeRenderer {
		public:
			mat4f* camera;

			virtual ~ShapeRenderer();
			virtual void begin(Camera& camera) = 0;
			virtual void end() = 0;
			virtual void line(vec3f a, vec3f b, vec3f colora, vec3f colorb) = 0;
			virtual void rect(vec2f pos, vec2f size, vec3f color) = 0;
	};
}
