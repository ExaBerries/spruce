#pragma once
#ifdef __APPLE__
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>
#include <graphics/renderer/api/metal/wrapper/MetalRenderPipelineState.h>
#include <graphics/renderer/api/metal/wrapper/MetalDepthStencilState.h>
#include <graphics/renderer/api/metal/wrapper/MetalBuffer.h>
#include <graphics/renderer/api/metal/wrapper/MetalTexture.h>
#include <graphics/renderer/api/metal/wrapper/MetalPrimitive.h>
#include <graphics/renderer/api/metal/wrapper/MetalIndexType.h>

namespace spruce {
	class MetalRenderCommandEncoder : public MetalObj {
		public:
			MetalRenderCommandEncoder(void* ptr);
			MetalRenderCommandEncoder(const MetalRenderCommandEncoder&) = delete;
			MetalRenderCommandEncoder(MetalRenderCommandEncoder&&) noexcept = delete;
			~MetalRenderCommandEncoder() override;

			void endEncoding() noexcept;
			void setRenderPipelineState(MetalRenderPipelineState* state) noexcept;
			void setDepthStencilState(MetalDepthStencilState* state) noexcept;
			void setViewport(vec2d pos, vec2d size, double near, double far) noexcept;

			void setVertexBuffer(const MetalBuffer* buffer, uint32 offset, uint32 index) noexcept;
			void setVertexBytes(const void* bytes, uint32 length, uint32 index) noexcept;
			void setVertexTexture(const MetalTexture* texture, uint32 index) noexcept;
			void setFragmentBuffer(const MetalBuffer* buffer, uint32 offset, uint32 index) noexcept;
			void setFragmentBytes(const void* bytes, uint32 length, uint32 index) noexcept;
			void setFragmentTexture(const MetalTexture* texture, uint32 index) noexcept;

			void drawPrimitives(MetalPrimitive primitive, uint32 vertexStart, uint32 vertexCount, uint32 instanceCount) noexcept;
			void drawIndexedPrimitives(MetalPrimitive primitive, uint32 indexCount, MetalIndexType type, const MetalBuffer* indexBuffer, uint32 indexBufferOffset) noexcept;

			MetalRenderCommandEncoder& operator=(const MetalRenderCommandEncoder&) = delete;
			MetalRenderCommandEncoder& operator=(MetalRenderCommandEncoder&&) noexcept = delete;
	};
}
#endif
