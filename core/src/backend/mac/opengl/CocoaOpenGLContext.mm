#include <backend/mac/opengl/CocoaOpenGLContext.h>

namespace spruce {
	CocoaOpenGLContext::CocoaOpenGLContext(OpenGLView* view) {
		this-> view = view;
	}

	void CocoaOpenGLContext::makeContextCurrent() {
		[[view getContext] makeCurrentContext];
	}

	void CocoaOpenGLContext::swapBuffers() {
		[[view getContext] flushBuffer];
	}

	void CocoaOpenGLContext::setSwapInverval(int32 interval) {
		[[view getContext] setValues:&interval forParameter:NSOpenGLCPSwapInterval];
	}
}
