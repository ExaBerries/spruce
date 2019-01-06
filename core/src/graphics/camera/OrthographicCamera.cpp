#include <graphics/camera/OrthographicCamera.h>

namespace spruce {
	namespace graphics {
		namespace camera {
			OrthographicCamera::OrthographicCamera(float viewportWidth, float viewportHeight, float near, float far, vec3f& up, vec3f& dir) : Camera(viewportWidth, viewportHeight) {
				this->near = near;
				this->far = far;
				this->dir = dir;
				this->up = up;
			}

			void OrthographicCamera::update(RendererAbstractor* renderer) {
				renderer->setOrthographic(projection, -viewportWidth / 2, viewportWidth / 2, viewportHeight / 2, viewportHeight / -2, near, far);
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
