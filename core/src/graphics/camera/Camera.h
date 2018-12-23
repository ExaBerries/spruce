#pragma once
#include <common.h>

namespace spruce {
	namespace graphics {
		namespace camera {
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
					Camera(const Camera& camera) = delete;
					virtual ~Camera();

					virtual void update() = 0;
					vec3f unproject(vec2f& vector, float depth);
					vec2f project(vec3f& vector);
			};
		}
	}

	using graphics::camera::Camera;
}