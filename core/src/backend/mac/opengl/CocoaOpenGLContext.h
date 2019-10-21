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
			CocoaOpenGLContext(const CocoaOpenGLContext&) = delete;
			CocoaOpenGLContext(CocoaOpenGLContext&&) noexcept = delete;
			~CocoaOpenGLContext() override = default;

			void makeContextCurrent() noexcept override;
			void swapBuffers() noexcept override;
			void setSwapInverval(int32 interval) noexcept override;

			CocoaOpenGLContext& operator=(const CocoaOpenGLContext&) = delete;
			CocoaOpenGLContext& operator=(CocoaOpenGLContext&&) noexcept = delete;
	};
}
#endif
