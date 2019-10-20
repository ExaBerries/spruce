#include <graphics/renderer/api/opengl/OpenGLColorRenderTarget.h>

namespace spruce {
	OpenGLColorRenderTarget::OpenGLColorRenderTarget(uint16 width, uint16 height, GLint internalFormat, GLenum externalFormat, GLenum type) {
		this->width = width;
		this->height = height;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, externalFormat, type, NULL);
	}

	OpenGLColorRenderTarget::~OpenGLColorRenderTarget() {
		glDeleteTextures(1, &texture);
	}

	void OpenGLColorRenderTarget::attachToBoundFramebuffer(GLenum attachment) {
		glFramebufferTexture(GL_FRAMEBUFFER, attachment, texture, 0);
	}

	void OpenGLColorRenderTarget::bind(GLenum unit) {
		glActiveTexture(unit);
		glBindTexture(GL_TEXTURE_2D, texture);
	}
}
