#pragma once
#include <common.h>
#include <graphics/renderer/api/opengl/glplatform.h>

namespace spruce {
	namespace graphics {
		class OpenGLContext {
			public:
				OpenGLContext() = default;
				virtual ~OpenGLContext() = default;

				virtual void makeContextCurrent() = 0;
				virtual void swapBuffers() = 0;
				virtual void setSwapInverval(int32 interval) = 0;
		};
	}

	using graphics::OpenGLContext;
}
