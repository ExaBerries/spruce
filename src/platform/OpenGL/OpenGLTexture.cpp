#include <platform/OpenGL/OpenGLTexture.h>

namespace spruce {
	OpenGLTexture::OpenGLTexture(uint8* data, uint16& width, uint16& height, uint16& bitsPerPixel) {
		texture = 0;
		this->data = data;
		this->width = width;
		this->height = height;
		this->bitsPerPixel = bitsPerPixel;
	}

	OpenGLTexture::~OpenGLTexture() {
	}

	void OpenGLTexture::bind(uint16 unit) {
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	void OpenGLTexture::toVRAM() {
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
