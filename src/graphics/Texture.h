#pragma once
#include <common.h>

namespace spruce {
	class Texture {
		public:
			uint8* data;
			uint16 width;
			uint16 height;
			uint16 bitsPerPixel;

			Texture(uint8* data, uint16& width, uint16& height, uint16& bitsPerPixel);
			Texture(const Texture& texture);
			virtual ~Texture();
			virtual void toVRAM() = 0;
			virtual void bind(uint16 unit) = 0;
	};
}
