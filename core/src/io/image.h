#pragma once
#include <common.h>
#include <io/FileHandle.h>

namespace spruce {
	namespace io {
		struct ImageData {
			buffer<uint8> data;
			uint16 width;
			uint16 height;
			uint16 bitsPerPixel;
		};

		[[nodiscard]] ImageData loadImage(const FileHandle& file);
		[[nodiscard]] buffer<uint8> loadImage(const FileHandle& file, uint16& width, uint16& height, uint16& bitsPerPixel);
	}
}
