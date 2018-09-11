#pragma once
#ifdef __linux__
#include <common.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <backend/api/opengl/platform.h>
#include <backend/linux/APIHook.h>

namespace spruce {
	class OpenGLHook : public APIHook {
		public:
			Display* display;
			XWindow window;
			GLXFBConfig fbConfig;
			GLXContext context;
			XVisualInfo* visualInfo;

			OpenGLHook(Display* display);
			virtual ~OpenGLHook();

			Visual* getVisual();
			uint32 getDepth();
			void windowCreated(XWindow window);
			void apiInitalized(XWindow window);
	};
}
#endif
