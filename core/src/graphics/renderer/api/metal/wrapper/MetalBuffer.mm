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

	void* MetalBuffer::getContents() {
		return castBuffer(ptr).contents;
	}

	void MetalBuffer::didModifyRange(uint32 start, uint32 length) {
		[castBuffer(ptr) didModifyRange:NSMakeRange(start, length)];
	}

	uint32 MetalBuffer::getLength() {
		return castBuffer(ptr).length;
	}
}
#endif
