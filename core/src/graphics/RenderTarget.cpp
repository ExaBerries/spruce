#include <graphics/RenderTarget.h>

namespace spruce {
	RenderTarget::RenderTarget(uint16 width, uint16 height) {
		this->width = width;
		this->height = height;
	}

	RenderTarget::~RenderTarget() {
	}
}
