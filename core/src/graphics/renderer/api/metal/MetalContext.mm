#include <graphics/renderer/api/metal/MetalContext.h>
#ifdef __APPLE__
#include <backend/mac/metal/MetalView.h>

namespace spruce {
	MetalContext::MetalContext(void* mtlView) {
		this->mtlView = mtlView;
		[((MetalView*) mtlView) setDevice:(__bridge id<MTLDevice>) this->device.ptr];
	}

	owner<MetalDrawable> MetalContext::getDrawable() {
		return new MetalDrawable((__bridge void*)[((MetalView*) mtlView) getDrawable]);
	}

	void MetalContext::setDrawableSize(vec2i size) {
		[((MetalView*) mtlView) setDrawableSize:size];
	}

	void MetalContext::setVSync(bool vsync) {
		[((MetalView*)mtlView) setVSync:vsync];
	}
}
#endif
