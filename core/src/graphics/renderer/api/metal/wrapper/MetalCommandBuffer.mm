#include <graphics/renderer/api/metal/wrapper/MetalCommandBuffer.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>

namespace spruce {
	MetalCommandBuffer::MetalCommandBuffer(void* ptr) : MetalObj(ptr) {
	}

	constexpr id<MTLCommandBuffer> castCmdBuffer(void* ptr) {
		return (__bridge id<MTLCommandBuffer>) ptr;
	}

	constexpr id<MTLDrawable> castDrawable(void* ptr) {
		return (__bridge id<MTLDrawable>) ptr;
	}

	constexpr MTLRenderPassDescriptor* castRPD(void* ptr) {
		return (__bridge MTLRenderPassDescriptor*) ptr;
	}

	void MetalCommandBuffer::commit() {
		[castCmdBuffer(ptr) commit];
	}

	void MetalCommandBuffer::enqueue() {
		[castCmdBuffer(ptr) enqueue];
	}

	void MetalCommandBuffer::presentDrawable(MetalDrawable* drawable) {
		[castCmdBuffer(ptr) presentDrawable:castDrawable(drawable->ptr)];
	}

	owner<MetalRenderCommandEncoder> MetalCommandBuffer::createRenderCommandEncoder(MetalRenderPassDescriptor& descriptor) {
		return new MetalRenderCommandEncoder([castCmdBuffer(ptr) renderCommandEncoderWithDescriptor:castRPD(descriptor.ptr)]);
	}
}
#endif
