#pragma once
#include <common.h>
#include <graphics/Texture.h>
#include <Metal/Metal.h>

namespace spruce {
	class MetalTexture : public Texture {
		public:
			id<MTLTexture> mtlTexture;

			MetalTexture(uint8* data, uint16& width, uint16& height, uint16& bitsPerPixel);
			MetalTexture(const MetalTexture& texture);
			~MetalTexture();

			void bind(uint16 unit);
			void toVRAM();
			void freeVRAM();
	};
}
