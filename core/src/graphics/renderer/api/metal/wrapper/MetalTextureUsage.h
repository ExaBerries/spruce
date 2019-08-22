#pragma once
#ifdef __APPLE__
#include <common.h>

namespace spruce {
	enum class MetalTextureUsage {
		UNKNOWN = 0,
		SHADER_READ = 1,
		SHADER_WRITE = 2,
		RENDER_TARGET = 4,
		PIXEL_FORMAT_VIEW = 8
	};

	MetalTextureUsage operator|(MetalTextureUsage a, MetalTextureUsage b);
}
#endif
