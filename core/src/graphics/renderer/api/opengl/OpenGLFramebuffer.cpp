#include <graphics/renderer/api/opengl/OpenGLFramebuffer.h>

namespace spruce {
	OpenGLFramebuffer::OpenGLFramebuffer() {
		glGenFramebuffers(1, &framebuffer);
		depthbuffer = 0;
	}

	OpenGLFramebuffer::~OpenGLFramebuffer() {
		if (depthbuffer != 0) {
			glDeleteRenderbuffers(1, &depthbuffer);
		}
		glDeleteFramebuffers(1, &framebuffer);
	}

	void OpenGLFramebuffer::bind() {
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	}

	bool OpenGLFramebuffer::complete() {
		bind();
		return (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE);
	}

	void OpenGLFramebuffer::setDrawBuffers(buffer<GLenum> attachments) {
		if (attachments.size == 0) {
			glDrawBuffer(GL_NONE);
			return;
		}
		GLint maxDrawBuffers = 0;
		glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxDrawBuffers);
		GLsizei attachSize = static_cast<GLsizei>(attachments.size);
		if (attachSize < maxDrawBuffers) {
			glDrawBuffers(attachSize, attachments);
		} else {
			serr("to many draw buffers (", attachments.size, ") only ", maxDrawBuffers, " supported");
		}
	}

	void OpenGLFramebuffer::createDepthRenderBuffer(uint16 width, uint16 height) {
		bind();
		glGenRenderbuffers(1, &depthbuffer);
		glBindRenderbuffer(GL_RENDERBUFFER, depthbuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthbuffer);
	}
}
