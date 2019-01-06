#pragma once
#include <graphics/camera/Camera.h>

namespace spruce {
	namespace graphics {
		namespace camera {
			class OrthographicCamera : public Camera {
				public:
					float near;
					float far;
					vec3f dir;
					vec3f up;

					OrthographicCamera(float viewportWidth, float viewportHeight, float near, float far, vec3f& up, vec3f& dir);
					OrthographicCamera(const OrthographicCamera& camera) = default;
					~OrthographicCamera() = default;

					void update(RendererAbstractor* renderer);
			};
		}
	}

	using graphics::camera::OrthographicCamera;
}
