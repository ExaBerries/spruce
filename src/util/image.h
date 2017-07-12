#pragma once
#include <common.h>
#include <string>

namespace spruce {
	namespace util {
		uint8* loadImage(std::string& path, uint16& width, uint16& height, uint16& bytes);
	}
}
