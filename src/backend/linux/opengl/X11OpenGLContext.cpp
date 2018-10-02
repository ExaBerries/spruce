//#include <backend/api/opengl/OpenGLContext.h>
#ifdef __linux__
#include <X11/X.h>
#include <X11/Xlib.h>
#include <backend/api/opengl/platform.h>
#include <backend/linux/X11Window.h>

namespace spruce {
	GLXContext* context;

	void makeContextCurrent(Window* window) {
		glXMakeCurrent(((X11Window*)window)->display, ((X11Window*)window)->window, *context);
	}

	void swapBuffers(Window* window) {
		glXSwapBuffers(((X11Window*)window)->display, ((X11Window*)window)->window);
	}

	void swapInterval(Window* window, uint8 interval) {
	}
}
#endif
