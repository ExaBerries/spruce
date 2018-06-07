#pragma once
#include <common.h>
#include <io/FileHandle.h>

namespace spruce {
	namespace io {
		buffer<uint8> loadImage(const FileHandle& file, uint16& width, uint16& height, uint16& bytes);
	}
}
