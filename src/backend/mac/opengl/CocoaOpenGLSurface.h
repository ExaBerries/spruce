#pragma once
#include <common.h>
#include <backend/RenderSurface.h>
#include <backend/mac/opengl/OpenGLView.h>

namespace spruce {
	class CocoaOpenGLSurface : public RenderSurface {
		public:
			OpenGLView* view;

			CocoaOpenGLSurface(OpenGLView* view);
			virtual ~CocoaOpenGLSurface();

			void renderStart();
			void renderEnd();
	};
}
