#pragma once
#include <common.h>

namespace spruce {
	class Texture {
		public:
			uint8* data;
			unsigned int width;
			unsigned int height;
			unsigned int bitsPerPixel;

			Texture();
			Texture(const Texture& texture);
			virtual ~Texture();
			virtual void toVRAM() = 0;
			virtual void bind(uint16 unit) = 0;
	};
}
