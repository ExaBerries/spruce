#pragma once
#include <common.h>
#include <graphics/renderer/api/APIContext.h>
#include <graphics/renderer/api/opengl/glplatform.h>

namespace spruce {
	namespace graphics {
		class OpenGLContext : public APIContext {
			public:
				OpenGLContext() = default;
				OpenGLContext(const OpenGLContext&) = delete;
				OpenGLContext(OpenGLContext&&) = delete;
				~OpenGLContext() = default;

				virtual void makeContextCurrent() = 0;
				virtual void swapBuffers() = 0;
				virtual void setSwapInverval(int32 interval) = 0;

				OpenGLContext& operator=(const OpenGLContext&) = delete;
				OpenGLContext& operator=(OpenGLContext&&) = delete;
		};
	}

	using graphics::OpenGLContext;
}
