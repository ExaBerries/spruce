#include <backend/api/opengl/OpenGLRenderTarget.h>
#include <graphics/graphics.h>
#include <backend/api/opengl/platform.h>
#include <backend/api/opengl/OpenGLTexture.h>

namespace spruce {
	OpenGLRenderTarget::OpenGLRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height) : RenderTarget(width, height) {
		glGenFramebuffers(1, &framebuffer);
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
		texture = new OpenGLTexture(format, nullptr, width, height);
		texture->toVRAM();
		if (format != Texture::DEPTH) {
			glGenRenderbuffers(1, &depthBuffer);
			glBindRenderbuffer(GL_RENDERBUFFER, depthBuffer);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthBuffer);
		} else {
			depthBuffer = 0;
		}
		if (format != Texture::DEPTH) {
			glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, texture->texture, 0);
			GLenum drawBuffers[1] = {GL_COLOR_ATTACHMENT0};
			glDrawBuffers(1, drawBuffers);
		} else {
			glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, texture->texture, 0);
			glDrawBuffer(GL_NONE);
		}
		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
			serr("error creating framebuffer");
		}
	}

	OpenGLRenderTarget::~OpenGLRenderTarget() {
		delete texture;
		glDeleteRenderbuffers(1, &depthBuffer);
		glDeleteFramebuffers(1, &framebuffer);
	}

	void OpenGLRenderTarget::bind() {
		texture->bind();
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	}
}
