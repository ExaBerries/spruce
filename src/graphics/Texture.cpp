#include <graphics/Texture.h>

namespace spruce {
	Texture::Texture(uint8* data, uint16& width, uint16& height, uint16& bitsPerPixel) {
		this->data = data;
		this->width = width;
		this->height = height;
		this->bitsPerPixel = bitsPerPixel;
	}

	Texture::Texture(const Texture& texture) {
		this->data = texture.data;
		this->width = texture.width;
		this->height = texture.height;
		this->bitsPerPixel = texture.bitsPerPixel;
	}

	Texture::~Texture() {
		delete[] data;
	}
}
