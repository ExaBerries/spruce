#pragma once
#ifdef __linux__
#include <common.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <graphics/renderer/api/opengl/OpenGLContext.h>
#include <graphics/renderer/api/opengl/glplatform.h>
#include <GL/glx.h>

using XWindow = Window;

namespace spruce {
	class X11OpenGLContext : public OpenGLContext {
		public:
			Display* display;
			XWindow window;
			GLXFBConfig fbConfig;
			GLXContext context;
			XVisualInfo* visualInfo;

			X11OpenGLContext(Display* display) noexcept;
			X11OpenGLContext(const X11OpenGLContext&) = delete;
			X11OpenGLContext(X11OpenGLContext&&) noexcept = delete;
			~X11OpenGLContext() noexcept final;

			[[nodiscard]] Visual* getVisual() noexcept;
			[[nodiscard]] uint32 getDepth() noexcept;
			void windowCreated(XWindow window) noexcept;

			void makeContextCurrent() noexcept final;
			void swapBuffers() noexcept final;
			void setSwapInverval(int32 interval) noexcept final;

			X11OpenGLContext& operator=(const X11OpenGLContext&) = delete;
			X11OpenGLContext& operator=(X11OpenGLContext&&) noexcept = delete;
	};
}
#endif
