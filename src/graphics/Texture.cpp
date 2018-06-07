#include <graphics/Texture.h>

namespace spruce {
	Texture::Texture(PixelFormat format, buffer<uint8> data, uint16& width, uint16& height) : data(data) {
		this->format = format;
		this->width = width;
		this->height = height;
	}

	Texture::~Texture() {
		data.free();
	}
}
