#pragma once

#ifdef __linux__
#include <common.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <backend/api/opengl/platform.h>
#include <backend/linux/X11RenderSurface.h>

namespace spruce {
	class X11OpenGLSurface : public X11RenderSurface {
		public:
			Display* display;
			XWindow window;
			GLXFBConfig fbConfig;
			GLXContext context;
			XVisualInfo* visualInfo;

			X11OpenGLSurface(Display* display);
			virtual ~X11OpenGLSurface();

			Visual* getVisual();
			uint32 getDepth();
			void windowCreated(XWindow window);
			void apiInitalized(XWindow window);
			void renderStart();
			void renderEnd();
	};
}
#endif
