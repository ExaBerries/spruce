#include <graphics/renderer/api/metal/wrapper/MetalDepthStencilState.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>

namespace spruce {
	constexpr id<MTLDepthStencilState> castDSS(void* ptr) noexcept {
		return (__bridge id<MTLDepthStencilState>) ptr;
	}

	MetalDepthStencilState::MetalDepthStencilState(void* ptr) : MetalObj(ptr) {
	}

	MetalDepthStencilState::~MetalDepthStencilState() {
		[castDSS(ptr) release];
	}

}
#endif
