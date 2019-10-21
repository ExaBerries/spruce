#include <graphics/renderer/api/metal/wrapper/MetalDrawable.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>

namespace spruce {
	constexpr id<CAMetalDrawable> castDrawable(void* ptr) noexcept {
		return (__bridge id<CAMetalDrawable>) ptr;
	}

	MetalDrawable::MetalDrawable(void* ptr) : MetalObj(ptr) {
		texture = new MetalTexture(castDrawable(ptr).texture);
	}

	MetalDrawable::~MetalDrawable() {
		delete (MetalTexture*)texture;
		[castDrawable(ptr) release];
	}
}
#endif
