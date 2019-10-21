#include <graphics/camera/Camera.h>

namespace spruce {
	namespace graphics {
		namespace camera {
			Camera::Camera(const float& viewportWidth, const float& viewportHeight) {
				this->viewportWidth = viewportWidth;
				this->viewportHeight = viewportHeight;
			}

			vec3f Camera::unproject(const vec2f& screen, float depth) const noexcept {
				float x = 2.0f * screen.x;
				float y = 2.0f * screen.y;
				float z = 2.0f * depth - 1.0f;
				vec4f vec(x, y, z, 1);
				vec = inverse * vec;
				vec /= vec.w;
				vec3f world(vec.x, vec.y, vec.z);
				return world;
			}

			vec2f Camera::project(const vec3f& world) const noexcept {
				vec4f projected = combined * vec4f(world, 1);
				projected /= projected.w;
				float x = projected.x / 2.0f;
				float y = projected.y / 2.0f;
				return vec2f(x, y);
			}
		}
	}
}
