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
			uint8* data;
			uint16 width;
			uint16 height;

			Texture(PixelFormat format, uint8* data, uint16& width, uint16& height);
			Texture(const Texture& texture);
			virtual ~Texture();

			virtual void toVRAM() = 0;
			virtual void freeVRAM() = 0;
			void bind();
			void unbind();
	};
}
