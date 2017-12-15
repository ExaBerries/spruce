#pragma once
#include <common.h>
#include <graphics/Texture.h>

namespace spruce {
	struct RenderBuffer {
		Texture::PixelFormat format;
		bool depth;
	};
}
