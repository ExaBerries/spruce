#include <backend/mac/opengl/CocoaOpenGLSurface.h>
#include <backend/api/opengl/OpenGLRenderTarget.h>
#include <graphics/graphics.h>

namespace spruce {
	CocoaOpenGLSurface::CocoaOpenGLSurface(OpenGLView* view) {
		this->view = view;
		this->target = new OpenGLRenderTarget();
	}

	CocoaOpenGLSurface::~CocoaOpenGLSurface() {
	}

	void CocoaOpenGLSurface::renderStart() {
		[[view getContext] makeCurrentContext];
		GLint interval = spruce::graphics::vsync;
		[[view getContext] setValues:&interval forParameter:NSOpenGLCPSwapInterval];
	}

	void CocoaOpenGLSurface::renderEnd() {
		[[view getContext] flushBuffer];
	}
}
