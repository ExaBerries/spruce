#include <graphics/command/texture/TextureBindCommand.h>
#include <graphics/command/texture/TextureUnbindCommand.h>
#include <graphics/Texture.h>
#include <graphics/graphics.h>

namespace spruce {
	Texture::Texture(PixelFormat format, buffer<uint8> data, uint16& width, uint16& height) : data(data) {
		this->format = format;
		this->width = width;
		this->height = height;
	}

	Texture::~Texture() {
		data.free();
	}

	void Texture::bind() {
		graphics::getCommandBuffer().add(new TextureBindCommand(this));
	}

	void Texture::unbind() {
		graphics::getCommandBuffer().add(new TextureUnbindCommand(this));
	}
}
