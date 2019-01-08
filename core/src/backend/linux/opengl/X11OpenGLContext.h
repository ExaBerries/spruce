#pragma once
#ifdef __linux__
#include <common.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <graphics/renderer/api/opengl/OpenGLContext.h>
#include <graphics/renderer/api/opengl/glplatform.h>

typedef Window XWindow;

namespace spruce {
	class X11OpenGLContext : public OpenGLContext {
		public:
			Display* display;
			XWindow window;
			GLXFBConfig fbConfig;
			GLXContext context;
			XVisualInfo* visualInfo;

			X11OpenGLContext(Display* display);
			~X11OpenGLContext();

			Visual* getVisual();
			uint32 getDepth();
			void windowCreated(XWindow window);
			void makeContextCurrent();
			void swapBuffers();
			void setSwapInverval(int32 interval);
	};
}
#endif
