#include <graphics/renderer/api/metal/wrapper/MetalRenderCommandEncoder.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>

namespace spruce {
	constexpr id<MTLRenderCommandEncoder> castRCE(void* ptr) noexcept {
		return (__bridge id<MTLRenderCommandEncoder>) ptr;
	}

	constexpr id<MTLRenderPipelineState> castRPS(void* ptr) noexcept {
		return (__bridge id<MTLRenderPipelineState>) ptr;
	}

	constexpr id<MTLDepthStencilState> castDSS(void* ptr) noexcept {
		return (__bridge id<MTLDepthStencilState>) ptr;
	}

	constexpr id<MTLBuffer> castBuffer(const void* ptr) noexcept {
		return (__bridge id<MTLBuffer>) ptr;
	}

	constexpr id<MTLTexture> castTexture(const void* ptr) noexcept {
		return (__bridge id<MTLTexture>) ptr;
	}

	MetalRenderCommandEncoder::MetalRenderCommandEncoder(void* ptr) : MetalObj(ptr) {
	}

	MetalRenderCommandEncoder::~MetalRenderCommandEncoder() {
		[castRCE(ptr) release];
	}

	void MetalRenderCommandEncoder::endEncoding() noexcept {
		[castRCE(ptr) endEncoding];
	}

	void MetalRenderCommandEncoder::setRenderPipelineState(MetalRenderPipelineState* state) noexcept {
		[castRCE(ptr) setRenderPipelineState:castRPS(state->ptr)];
	}

	void MetalRenderCommandEncoder::setDepthStencilState(MetalDepthStencilState* state) noexcept {
		[castRCE(ptr) setDepthStencilState:castDSS(state->ptr)];
	}

	void MetalRenderCommandEncoder::setViewport(vec2d pos, vec2d size, double near, double far) noexcept {
		MTLViewport viewport = {pos.x, pos.y, size.x, size.y, near, far};
		[castRCE(ptr) setViewport:viewport];
	}

	void MetalRenderCommandEncoder::setVertexBuffer(const MetalBuffer* buffer, uint32 offset, uint32 index) noexcept {
		[castRCE(ptr) setVertexBuffer:castBuffer(buffer->ptr) offset:offset atIndex:index];
	}

	void MetalRenderCommandEncoder::setVertexBytes(const void* bytes, uint32 length, uint32 index) noexcept {
		[castRCE(ptr) setVertexBytes:bytes length:length atIndex:index];
	}

	void MetalRenderCommandEncoder::setVertexTexture(const MetalTexture* texture, uint32 index) noexcept {
		[castRCE(ptr) setVertexTexture:castTexture(texture->ptr) atIndex:index];
	}

	void MetalRenderCommandEncoder::setFragmentBuffer(const MetalBuffer* buffer, uint32 offset, uint32 index) noexcept {
		[castRCE(ptr) setFragmentBuffer:castBuffer(buffer->ptr) offset:offset atIndex:index];
	}

	void MetalRenderCommandEncoder::setFragmentBytes(const void* bytes, uint32 length, uint32 index) noexcept {
		[castRCE(ptr) setFragmentBytes:bytes length:length atIndex:index];
	}

	void MetalRenderCommandEncoder::setFragmentTexture(const MetalTexture* texture, uint32 index) noexcept {
		[castRCE(ptr) setFragmentTexture:castTexture(texture->ptr) atIndex:index];
	}

	void MetalRenderCommandEncoder::drawPrimitives(MetalPrimitive primitive, uint32 vertexStart, uint32 vertexCount, uint32 instanceCount) noexcept {
		[castRCE(ptr) drawPrimitives:mapPrimitive(primitive) vertexStart:vertexStart vertexCount:vertexCount instanceCount:instanceCount];
	}

	void MetalRenderCommandEncoder::drawIndexedPrimitives(MetalPrimitive primitive, uint32 indexCount, MetalIndexType type, const MetalBuffer* indexBuffer, uint32 indexBufferOffset) noexcept {
		[castRCE(ptr) drawIndexedPrimitives:mapPrimitive(primitive) indexCount:indexCount indexType:mapIndexType(type) indexBuffer:castBuffer(indexBuffer->ptr) indexBufferOffset:indexBufferOffset];
	}
}
#endif
