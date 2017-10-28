#include <backend/api/opengl/OpenGLContext.h>
#include <backend/mac/CocoaWindow.h>
#include <backend/mac/opengl/OpenGLView.h>

namespace spruce {
	void makeContextCurrent(Window* window) {
		CocoaWindow* cocoaWindow = (CocoaWindow*) window;
		OpenGLView* openGLView = (OpenGLView*) cocoaWindow->view;
		[[openGLView getContext] makeCurrentContext];
	}

	void swapBuffers(Window* window) {
		CocoaWindow* cocoaWindow = (CocoaWindow*) window;
		OpenGLView* openGLView = (NSView*) cocoaWindow->view;
		[[openGLView getContext] flushBuffer];
	}

	void swapInterval(Window* window, uint8 swapInterval) {
		GLint interval = swapInterval;
		CocoaWindow* cocoaWindow = (CocoaWindow*) window;
		OpenGLView* openGLView = (NSView*) cocoaWindow->view;
		[[openGLView getContext] setValues:&interval forParameter:NSOpenGLCPSwapInterval];
	}
}
