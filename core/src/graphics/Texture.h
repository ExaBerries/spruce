#pragma once
#include <common.h>
#include <graphics/TextureAPIData.h>
#include <graphics/renderer/RendererAbstractorFwd.h>

namespace spruce {
	namespace graphics {
		class Texture {
			public:
				enum PixelFormat {
					RGB,
					RGBA,
					DEPTH,
					RED
				};
				PixelFormat format;
				buffer<uint8> data;
				uint16 width;
				uint16 height;
				TextureAPIData* apiData;

				Texture(const PixelFormat& format, buffer<uint8>& data, const uint16& width, const uint16& height);
				Texture(const Texture& texture) = delete;
				Texture(Texture&&) noexcept = delete;
				virtual ~Texture();

				void toVRAM(RendererAbstractor* renderer);
				void freeVRAM();

				Texture& operator=(const Texture&) = delete;
				Texture& operator=(Texture&&) noexcept = delete;
		};
	}

	using graphics::Texture;
}
