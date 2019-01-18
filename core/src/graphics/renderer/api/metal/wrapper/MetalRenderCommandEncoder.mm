#include <graphics/renderer/api/metal/wrapper/MetalRenderCommandEncoder.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>

namespace spruce {
	MetalRenderCommandEncoder::MetalRenderCommandEncoder(void* ptr) : MetalObj(ptr) {
	}

	MetalRenderCommandEncoder::~MetalRenderCommandEncoder() {
		//[release];
	}

	constexpr id<MTLRenderCommandEncoder> castRCE(void* ptr) {
		return (__bridge id<MTLRenderCommandEncoder>) ptr;
	}

	constexpr id<MTLRenderPipelineState> castRPS(void* ptr) {
		return (__bridge id<MTLRenderPipelineState>) ptr;
	}

	constexpr id<MTLBuffer> castBuffer(const void* ptr) {
		return (__bridge id<MTLBuffer>) ptr;
	}

	constexpr id<MTLTexture> castTexture(const void* ptr) {
		return (__bridge id<MTLTexture>) ptr;
	}

	void MetalRenderCommandEncoder::setRenderPipelineState(MetalRenderPipelineState* state) {
		[castRCE(ptr) setRenderPipelineState:castRPS(state->ptr)];
	}

	void MetalRenderCommandEncoder::setDepthStencilState() {
		//[castRCE(ptr) setDepthStencilState:castDSS(state->ptr)];
	}

	void MetalRenderCommandEncoder::setViewport(vec2d pos, vec2d size, double near, double far) {
		MTLViewport viewport = {pos.x, pos.y, size.x, size.y, near, far};
		[castRCE(ptr) setViewport:viewport];
	}

	void MetalRenderCommandEncoder::setVertexBuffer(const MetalBuffer* buffer, uint32 offset, uint32 index) {
		[castRCE(ptr) setVertexBuffer:castBuffer(buffer->ptr) offset:offset atIndex:index];
	}

	void MetalRenderCommandEncoder::setVertexBytes(const void* bytes, uint32 length, uint32 index) {
		[castRCE(ptr) setVertexBytes:bytes length:length atIndex:index];
	}

	void MetalRenderCommandEncoder::setVertexTexture(const MetalTexture* texture, uint32 index) {
		[castRCE(ptr) setVertexTexture:castTexture(texture->ptr) atIndex:index];
	}

	void MetalRenderCommandEncoder::setFragmentBuffer(const MetalBuffer* buffer, uint32 offset, uint32 index) {
		[castRCE(ptr) setFragmentBuffer:castBuffer(buffer->ptr) offset:offset atIndex:index];
	}

	void MetalRenderCommandEncoder::setFragmentBytes(const void* bytes, uint32 length, uint32 index) {
		[castRCE(ptr) setFragmentBytes:bytes length:length atIndex:index];
	}

	void MetalRenderCommandEncoder::setFragmentTexture(const MetalTexture* texture, uint32 index) {
		[castRCE(ptr) setFragmentTexture:castTexture(texture->ptr) atIndex:index];
	}

	void MetalRenderCommandEncoder::drawPrimitives(MetalPrimitive primitive, uint32 vertexStart, uint32 vertexCount, uint32 instanceCount) {
		[castRCE(ptr) drawPrimitives:mapPrimitive(primitive) vertexStart:vertexStart vertexCount:vertexCount instanceCount:instanceCount];
	}

	void MetalRenderCommandEncoder::drawIndexedPrimitives(MetalPrimitive primitive, uint32 indexCount, MetalIndexType type, const MetalBuffer* indexBuffer, uint32 indexBufferOffset) {
		[castRCE(ptr) drawIndexedPrimitives:mapPrimitive(primitive) indexCount:indexCount indexType:mapIndexType(type) indexBuffer:castBuffer(indexBuffer->ptr) indexBufferOffset:indexBufferOffset];
	}
}
#endif
