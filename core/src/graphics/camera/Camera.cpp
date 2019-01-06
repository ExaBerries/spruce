#include <graphics/camera/Camera.h>

namespace spruce {
	namespace graphics {
		namespace camera {
			Camera::Camera(const float& viewportWidth, const float& viewportHeight) {
				this->viewportWidth = viewportWidth;
				this->viewportHeight = viewportHeight;
			}

			vec3f Camera::unproject(const vec2f& screen, float depth) {
				float x = 2.0 * screen.x;
				float y = 2.0 * screen.y;
				float z = 2.0 * depth - 1;
				vec4f vec(x, y, z, 1);
				vec = inverse * vec;
				vec /= vec.w;
				vec3f world(vec.x, vec.y, vec.z);
				return world;
			}

			vec2f Camera::project(const vec3f& world) {
				vec4f projected = combined * vec4f(world, 1);
				projected /= projected.w;
				float x = projected.x / 2.0;
				float y = projected.y / 2.0;
				return vec2f(x, y);
			}
		}
	}
}
