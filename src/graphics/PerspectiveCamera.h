#pragma once
#include <common.h>
#include <graphics/Camera.h>
#include <cmath>

namespace spruce {
	namespace graphics {
		class PerspectiveCamera: public Camera {
			public:
				float fieldOfView;
				float near;
				float far;

				PerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far);
				virtual ~PerspectiveCamera();
				void update();
		};
	}
}
