#pragma once
#include <common.h>
#include <graphics/renderer/api/opengl/glplatform.h>

namespace spruce {
	class OpenGLColorRenderTarget {
		public:
			GLuint texture;
			uint16 width;
			uint16 height;

			OpenGLColorRenderTarget(uint16 width, uint16 height, GLenum internalFormat, GLenum externalFormat, GLenum type);
			OpenGLColorRenderTarget(const OpenGLColorRenderTarget&) = delete;
			OpenGLColorRenderTarget(OpenGLColorRenderTarget&&) noexcept = delete;
			~OpenGLColorRenderTarget();

			void attachToBoundFramebuffer(GLenum attachment);
			void bind(GLenum unit);

 			OpenGLColorRenderTarget& operator=(const OpenGLColorRenderTarget&) = delete;
 			OpenGLColorRenderTarget& operator=(OpenGLColorRenderTarget&&) noexcept = delete;
	};
}
