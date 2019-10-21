#include <graphics/renderer/api/metal/wrapper/MetalCommandQueue.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>

namespace spruce {
	MetalCommandQueue::MetalCommandQueue(void* ptr) : MetalObj(ptr) {
	}

	constexpr id<MTLCommandQueue> castQueue(void* ptr) noexcept {
		return (__bridge id<MTLCommandQueue>) ptr;
	}

	[[nodiscard]] owner<MetalCommandBuffer> MetalCommandQueue::createCommandBuffer() noexcept {
		return new MetalCommandBuffer([castQueue(ptr) commandBuffer]);
	}
}
#endif
