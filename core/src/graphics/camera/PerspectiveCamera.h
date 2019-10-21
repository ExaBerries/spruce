#pragma once
#include <common.h>
#include <graphics/camera/Camera.h>

namespace spruce {
	namespace graphics {
		namespace camera {
			class PerspectiveCamera : public Camera {
				public:
					float fieldOfView;
					float near;
					float far;
					vec3f up;
					vec3f dir;

					PerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far, const vec3f& up, const vec3f& dir);
					PerspectiveCamera(const PerspectiveCamera& camera) = default;
					PerspectiveCamera(PerspectiveCamera&&) noexcept = default;
					~PerspectiveCamera() override = default;

					void update(RendererAbstractor* renderer) noexcept final;

					PerspectiveCamera& operator=(const PerspectiveCamera&) = default;
					PerspectiveCamera& operator=(PerspectiveCamera&&) noexcept = default;
			};
		}
	}

	using graphics::camera::PerspectiveCamera;
}
