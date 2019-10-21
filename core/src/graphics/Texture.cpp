#include <graphics/Texture.h>
#include <graphics/renderer/RendererAbstractor.h>

namespace spruce {
	namespace graphics {
		Texture::Texture(const PixelFormat& format, buffer<uint8>& data, const uint16& width, const uint16& height) : data(data) {
			this->format = format;
			this->width = width;
			this->height = height;
			this->apiData = nullptr;
		}

		Texture::~Texture() {
			freeVRAM();
			data.free();
		}

		void Texture::toVRAM(RendererAbstractor* renderer) noexcept {
			apiData = renderer->createTextureAPIData(*this);
		}

		void Texture::freeVRAM() noexcept {
			delete apiData;
			apiData = nullptr;
		}
	}
}
