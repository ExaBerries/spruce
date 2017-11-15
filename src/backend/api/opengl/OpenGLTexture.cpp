#include <backend/api/opengl/OpenGLTexture.h>

namespace spruce {
	OpenGLTexture::OpenGLTexture(uint8* data, uint16& width, uint16& height, uint16& bitsPerPixel) : Texture(data, width, height, bitsPerPixel) {
		texture = 0;
	}

	OpenGLTexture::OpenGLTexture(const OpenGLTexture& texture) : Texture(texture) {
		this->texture = texture.texture;
	}

	OpenGLTexture::~OpenGLTexture() {
		freeVRAM();
	}

	void OpenGLTexture::bind(uint16 unit) {
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	void OpenGLTexture::toVRAM() {
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void OpenGLTexture::freeVRAM() {
		glDeleteTextures(1, &texture);
	}
}
