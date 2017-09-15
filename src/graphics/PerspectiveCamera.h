#pragma once
#include <common.h>
#include <graphics/Camera.h>

namespace spruce {
	class PerspectiveCamera: public Camera {
		public:
			float fieldOfView;
			float near;
			float far;
			vec3f up;
			vec3f dir;

			PerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far, vec3f& up, vec3f& dir);
			virtual ~PerspectiveCamera();
			void update();
	};
}
