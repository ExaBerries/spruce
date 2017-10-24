#pragma once
#include <common.h>

namespace spruce {
	namespace io {
		uint8* loadImage(string& path, uint16& width, uint16& height, uint16& bytes);
	}
}
