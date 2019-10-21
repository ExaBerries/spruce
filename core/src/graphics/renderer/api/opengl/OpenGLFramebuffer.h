#pragma once
#include <common.h>
#include <graphics/renderer/api/opengl/glplatform.h>

namespace spruce {
	class OpenGLFramebuffer {
		public:
			GLuint framebuffer;
			GLuint depthbuffer;

			OpenGLFramebuffer();
			OpenGLFramebuffer(const OpenGLFramebuffer&) = delete;
			OpenGLFramebuffer(OpenGLFramebuffer&&) noexcept = default;
			~OpenGLFramebuffer();

			void bind() noexcept;
			[[nodiscard]] bool complete() noexcept;
			void setDrawBuffers(buffer<GLenum> attachments) noexcept;
			void createDepthRenderBuffer(uint16 width, uint16 height) noexcept;

			OpenGLFramebuffer& operator=(const OpenGLFramebuffer) = delete;
			OpenGLFramebuffer& operator=(OpenGLFramebuffer&&) noexcept = delete;
	};
}
