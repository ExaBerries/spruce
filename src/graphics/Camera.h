#pragma once
#include <common.h>
#include <math/math.h>

namespace spruce {
	class Camera {
		public:
			mat4f projection;
			mat4f view;
			mat4f combined;
			mat4f inverse;
			vec3f position;
			quaternion rotation;
			float viewportWidth;
			float viewportHeight;

			Camera(float viewportWidth, float viewportHeight);
			virtual ~Camera();

			virtual void update() = 0;
			vec3f unproject(vec2f& vector);
			vec2f project(vec3f& vector);
	};
}
