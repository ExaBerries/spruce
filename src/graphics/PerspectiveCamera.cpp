#include "PerspectiveCamera.h"

namespace spruce {
	namespace graphics {
		PerspectiveCamera::PerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far) : Camera(viewportWidth, viewportHeight) {
			this->viewportWidth = viewportWidth;
			this->viewportHeight = viewportHeight;
			this->fieldOfView = fieldOfView;
			this->near = near;
			this->far = far;
		}

		PerspectiveCamera::~PerspectiveCamera() {
		}

		void PerspectiveCamera::update() {
			float aspectRatio = viewportWidth / viewportHeight;
			float absNear = std::abs(near);
			float absFar = std::abs(far);
			projection = mat4f(absNear, absFar, fieldOfView, aspectRatio);
		}
	}
}
