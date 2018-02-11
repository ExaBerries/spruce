#include <backend/api/opengl/OpenGLTexture.h>
#include <backend/api/opengl/platform.h>

namespace spruce {
	int32 OpenGLTexture::maxUnit = -1;
	bool* OpenGLTexture::units = nullptr;

	OpenGLTexture::OpenGLTexture(PixelFormat format, uint8* data, uint16& width, uint16& height) : Texture(format, data, width, height) {
		texture = 0;
		unit = 0;
	}

	OpenGLTexture::OpenGLTexture(const OpenGLTexture& texture) : Texture(texture) {
		this->texture = texture.texture;
		this->unit = texture.unit;
	}

	OpenGLTexture::~OpenGLTexture() {
		freeVRAM();
		unbind();
	}

	void OpenGLTexture::bind() {
		if (!unit) {
			unit = getFreeUnit();
			units[unit] = true;
		}
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	void OpenGLTexture::unbind() {
		if (units != nullptr) {
			units[unit] = false;
			unit = 0;
		}
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void OpenGLTexture::toVRAM() {
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		GLenum internal;
		GLenum external;
		GLenum type;
		if (format == Texture::RGB) {
			internal = GL_RGB;
			external = GL_RGB;
			type = GL_UNSIGNED_BYTE;
		} else if (format == Texture::RGBA) {
			internal = GL_RGBA;
			external = GL_RGBA;
			type = GL_UNSIGNED_BYTE;
		} else if (format == Texture::DEPTH) {
			internal = GL_DEPTH_COMPONENT16;
			external = GL_DEPTH_COMPONENT;
			type = GL_FLOAT;
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
		} else if (format == Texture::RED) {
			internal = GL_RED;
			external = GL_RED;
			type = GL_FLOAT;
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		} else {
			log("unknown pixel format");
			return;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, internal, width, height, 0, external, type, data);
	}

	void OpenGLTexture::freeVRAM() {
		glDeleteTextures(1, &texture);
	}

	uint16 OpenGLTexture::getFreeUnit() {
		if (units == nullptr) {
			glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &maxUnit);
			units = new bool[maxUnit];
			for (uint16 i = 0; i < maxUnit; i++) {
				units[i] = false;
			}
		}
		for (uint16 i = 1; i < maxUnit; i++) {
			if (units[i] == false) {
				return i;
			}
		}
		log("no texture unit available");
		return 0;
	}
}
