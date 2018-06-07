#pragma once
#include <common.h>

namespace spruce {
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

			Texture(PixelFormat format, buffer<uint8> data, uint16& width, uint16& height);
			Texture(const Texture& texture) = delete;
			virtual ~Texture();

			virtual void toVRAM() = 0;
			virtual void freeVRAM() = 0;
			virtual void bind() = 0;
			virtual void unbind() = 0;
	};
}
