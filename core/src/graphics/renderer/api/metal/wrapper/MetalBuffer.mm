#include <graphics/renderer/api/metal/wrapper/MetalBuffer.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>

namespace spruce {
	constexpr id<MTLBuffer> castBuffer(void* ptr) {
		return (__bridge id<MTLBuffer>) ptr;
	}

	MetalBuffer::MetalBuffer(void* ptr) : MetalObj(ptr) {
	}

	MetalBuffer::~MetalBuffer() {
		[castBuffer(ptr) release];
	}

	void* MetalBuffer::getContents() noexcept {
		return castBuffer(ptr).contents;
	}

	void MetalBuffer::didModifyRange(uint32 start, uint32 length) noexcept {
		[castBuffer(ptr) didModifyRange:NSMakeRange(start, length)];
	}

	uint64 MetalBuffer::getLength() noexcept {
		return castBuffer(ptr).length;
	}
}
#endif
