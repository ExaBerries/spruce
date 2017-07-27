#include <graphics/OrthographicCamera.h>

namespace spruce {
	OrthographicCamera::OrthographicCamera(float viewportWidth, float viewportHeight, float near, float far, vec3f& up) : Camera(viewportWidth, viewportHeight) {
		this->near = near;
		this->far = far;
		this->up = up;
	}

	OrthographicCamera::~OrthographicCamera() {
	}

	void OrthographicCamera::update() {
		projection.set(-viewportWidth / 2, viewportWidth / 2, -viewportHeight / 2, viewportHeight / 2, near, far);
		vec3f dir = vec3f(1, 0, 0) * rotation;
		view.set(dir, up);
		vec3f pos = position * -1;
		quaternion identityQuat(0, 0, 0, 1);
		vec3f scale(1, 1, 1);
		view *= mat4f(pos, identityQuat, scale);
		combined = projection * view;
	}
}
