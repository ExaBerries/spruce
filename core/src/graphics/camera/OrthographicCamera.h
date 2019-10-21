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

					OrthographicCamera(float viewportWidth, float viewportHeight, float near, float far, const vec3f& up, const vec3f& dir);
					OrthographicCamera(const OrthographicCamera& camera) = default;
					OrthographicCamera(OrthographicCamera&&) noexcept = default;
					~OrthographicCamera() override = default;

					void update(RendererAbstractor* renderer) noexcept final;

					OrthographicCamera& operator=(const OrthographicCamera&) = default;
					OrthographicCamera& operator=(OrthographicCamera&&) noexcept = default;
			};
		}
	}

	using graphics::camera::OrthographicCamera;
}
