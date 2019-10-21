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
				~OpenGLContext() override = default;

				virtual void makeContextCurrent() noexcept = 0;
				virtual void swapBuffers() noexcept = 0;
				virtual void setSwapInverval(int32 interval) noexcept = 0;

				OpenGLContext& operator=(const OpenGLContext&) = delete;
				OpenGLContext& operator=(OpenGLContext&&) = delete;
		};
	}

	using graphics::OpenGLContext;
}
