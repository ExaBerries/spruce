#include <graphics/renderer/api/metal/wrapper/MetalTexture.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>

namespace spruce {
	constexpr id<MTLTexture> castTexture(void* ptr) noexcept {
		return (__bridge id<MTLTexture>) ptr;
	}

	MetalTexture::MetalTexture(void* ptr) : MetalObj(ptr) {
	}

	MetalTexture::~MetalTexture() {
		[castTexture(ptr) release];
	}

	vec2i MetalTexture::getSize() noexcept {
		return {(int32)castTexture(ptr).width, (int32)castTexture(ptr).height};
	}
}
#endif
