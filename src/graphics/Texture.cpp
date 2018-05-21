#include <graphics/Texture.h>
#include <graphics/command/TextureBindCommand.h>
#include <graphics/command/TextureUnbindCommand.h>
#include <graphics/graphics.h>

namespace spruce {
	Texture::Texture(PixelFormat format, uint8* data, uint16& width, uint16& height) {
		this->format = format;
		this->data = data;
		this->width = width;
		this->height = height;
	}

	Texture::Texture(const Texture& texture) {
		this->format = texture.format;
		this->data = texture.data;
		this->width = texture.width;
		this->height = texture.height;
	}

	Texture::~Texture() {
		delete[] data;
	}

	void Texture::bind() {
		graphics::getCommandBuffer().add(new TextureBindCommand(this));
	}

	void Texture::unbind() {
		graphics::getCommandBuffer().add(new TextureUnbindCommand(this));
	}
}
