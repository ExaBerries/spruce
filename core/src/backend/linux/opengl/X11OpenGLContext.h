#pragma once
#ifdef __linux__
#include <common.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <graphics/renderer/api/opengl/OpenGLContext.h>
#include <graphics/renderer/api/opengl/glplatform.h>
#include <GL/glx.h>

typedef Window XWindow;

namespace spruce {
	class X11OpenGLContext : public OpenGLContext {
		public:
			Display* display;
			XWindow window;
			GLXFBConfig fbConfig;
			GLXContext context;
			XVisualInfo* visualInfo;

			X11OpenGLContext(Display* display) noexcept;
			~X11OpenGLContext() noexcept;

			[[nodiscard]] Visual* getVisual() noexcept;
			[[nodiscard]] uint32 getDepth() noexcept;
			void windowCreated(XWindow window) noexcept;

			void makeContextCurrent() noexcept override;
			void swapBuffers() noexcept override;
			void setSwapInverval(int32 interval) noexcept override;
	};
}
#endif
