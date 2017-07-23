#include <graphics/Camera.h>
#include <graphics/graphics.h>

namespace spruce {
	Camera::Camera(float viewportWidth, float viewportHeight) {
		this->viewportWidth = viewportWidth;
		this->viewportHeight = viewportHeight;
	}

	Camera::~Camera() {
	}

	vec3f Camera::unproject(vec2f& screen) {
		float x = 2.0 * screen.x / viewportWidth - 1;
		float y = 2.0 * (graphics::getHeight() - screen.y - 1) / viewportHeight - 1;
		float z = -1;
		// project vector inverse
		vec3f world = vec3f(x, y, z);
		return world;
	}

	vec2f Camera::project(vec3f& world) {
		vec3f projected = vec3f(world.x, world.y, world.z) * combined;
		float x = viewportWidth * (projected.x + 1) / 2;
		float y = viewportHeight * (projected.y + 1) / 2;
		return vec2f(x, y);
	}
}
