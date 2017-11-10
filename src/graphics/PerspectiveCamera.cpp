#include <graphics/PerspectiveCamera.h>
#include <app.h>
#include <cmath>

namespace spruce {
	PerspectiveCamera::PerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far, vec3f& up, vec3f& dir) : Camera(viewportWidth, viewportHeight) {
		this->fieldOfView = fieldOfView;
		this->near = near;
		this->far = far;
		this->up = up;
		this->dir = dir;
	}

	PerspectiveCamera::~PerspectiveCamera() {
	}

	void PerspectiveCamera::update() {
		float aspectRatio = viewportWidth / viewportHeight;
		float absNear = std::abs(near);
		float absFar = std::abs(far);
		projection.set(absNear, absFar, fieldOfView, aspectRatio);
		vec3f dir = this->dir * rotation;
		dir.nor();
		vec3f up = this->up * rotation;
		up.nor();
		view.set(dir, up);
		vec3f pos = position * -1;
		quaternion identityQuat(0, 0, 0, 1);
		vec3f scale(1, 1, 1);
		view *= mat4f(pos, identityQuat, scale);
		if (app::apiType == app::METAL) {
			mat4f metalTrans;
			metalTrans.values[11] = 0.5;
			combined = projection * metalTrans * view;
		} else {
			combined = projection * view;
		}
	}
}
