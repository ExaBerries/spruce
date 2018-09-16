#include <app.h>
#include <backend/api/RenderAPI.h>
#include <graphics/camera/PerspectiveCamera.h>

namespace spruce {
	namespace graphics {
		namespace camera {
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
				app::api->setPerspective(projection, absNear, absFar, fieldOfView, aspectRatio);
				vec3f dir = this->dir * rotation;
				dir.nor();
				vec3f up = this->up * rotation;
				up.nor();
				view.set(dir, up);
				vec3f pos = position * -1;
				quaternion identityQuat(0, 0, 0, 1);
				vec3f scale(1, 1, 1);
				view *= mat4f(pos, identityQuat, scale);
				combined = projection * view;
				inverse = mat4f(combined).invert();
			}
		}
	}
}
