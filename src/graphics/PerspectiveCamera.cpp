#include <graphics/PerspectiveCamera.h>
#include <cmath>

namespace spruce {
	PerspectiveCamera::PerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far, vec3f& up) : Camera(viewportWidth, viewportHeight) {
		this->fieldOfView = fieldOfView;
		this->near = near;
		this->far = far;
		this->up = up;
	}

	PerspectiveCamera::~PerspectiveCamera() {
	}

	void PerspectiveCamera::update() {
		float aspectRatio = viewportWidth / viewportHeight;
		float absNear = std::abs(near);
		float absFar = std::abs(far);
		projection.set(absNear, absFar, fieldOfView, aspectRatio);
		vec3f dir = vec3f(1, 0, 0) * rotation;
		view.set(dir, up);
		vec3f pos = position * -1;
		quaternion identityQuat(0, 0, 0, 1);
		vec3f scale(1, 1, 1);
		view *= mat4f(pos, identityQuat, scale);
		combined = projection * view;
	}
}
