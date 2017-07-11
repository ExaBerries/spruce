#pragma once
#include "../math/vec3f.h"
#include "../math/mat4f.h"
#include "../math/quaternion.h"

namespace spruce {
	namespace graphics {
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

				virtual void update();
				vec3f unproject(vec2f& vector);
				vec2f project(vec3f& vector);
		};
	}
}
