#pragma once
#include <graphics/RenderTarget.h>
#include <backend/api/opengl/platform.h>
#include <backend/api/opengl/OpenGLTexture.h>

namespace spruce {
	class OpenGLRenderTarget : public RenderTarget {
		public:
			GLuint framebuffer;
			OpenGLTexture* texture;
			GLuint depthBuffer;

			OpenGLRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height);
			virtual ~OpenGLRenderTarget();

			void bind();
	};
}
