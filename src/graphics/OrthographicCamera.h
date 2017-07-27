#pragma once
#include <graphics/Camera.h>

namespace spruce {
	class OrthographicCamera: public Camera {
		public:
			float near;
			float far;
			vec3f up;

			OrthographicCamera(float viewportWidth, float viewportHeight, float near, float far, vec3f& up);
			virtual ~OrthographicCamera();

			void update();
	};
}
