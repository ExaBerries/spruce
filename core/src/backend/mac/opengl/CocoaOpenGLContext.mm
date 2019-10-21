#ifdef __APPLE__
#include <backend/mac/opengl/CocoaOpenGLContext.h>

namespace spruce {
	CocoaOpenGLContext::CocoaOpenGLContext(OpenGLView* view) {
		this-> view = view;
	}

	void CocoaOpenGLContext::makeContextCurrent() noexcept {
		[[view getContext] makeCurrentContext];
	}

	void CocoaOpenGLContext::swapBuffers() noexcept {
		[[view getContext] flushBuffer];
	}

	void CocoaOpenGLContext::setSwapInverval(int32 interval) noexcept {
		[[view getContext] setValues:&interval forParameter:NSOpenGLCPSwapInterval];
	}
}
#endif
