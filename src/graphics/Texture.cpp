#include <graphics/Texture.h>

namespace spruce {
	Texture::Texture() {
		data = nullptr;
		width = 0;
		height = 0;
		bitsPerPixel = 0;
	}

	Texture::Texture(const Texture& texture) {
		this->data = texture.data;
		this->width = texture.width;
		this->height = texture.height;
		this->bitsPerPixel = texture.bitsPerPixel;
	}

	Texture::~Texture() {
		delete data;
	}
}
