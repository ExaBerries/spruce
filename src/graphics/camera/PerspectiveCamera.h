#pragma once
#include <common.h>
#include <graphics/camera/Camera.h>

namespace spruce {
	namespace graphics {
		namespace camera {
			class PerspectiveCamera: public Camera {
				public:
					float fieldOfView;
					float near;
					float far;
					vec3f up;
					vec3f dir;

					PerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far, vec3f& up, vec3f& dir);
					PerspectiveCamera(const PerspectiveCamera& camera) = delete;
					virtual ~PerspectiveCamera();

					void update();
			};
		}
	}

	using graphics::camera::PerspectiveCamera;
}
