#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/opengl/OpenGLContext.h>
#include <backend/mac/opengl/OpenGLView.h>

namespace spruce {
	class CocoaOpenGLContext : public OpenGLContext {
		public:
			OpenGLView* view;

			CocoaOpenGLContext(OpenGLView* view);
			~CocoaOpenGLContext() = default;

			void makeContextCurrent();
			void swapBuffers();
			void setSwapInverval(int32 interval);
	};
}
#endif