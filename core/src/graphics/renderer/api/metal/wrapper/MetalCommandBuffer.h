#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>
#include <graphics/renderer/api/metal/wrapper/MetalDrawable.h>
#include <graphics/renderer/api/metal/wrapper/MetalRenderCommandEncoder.h>
#include <graphics/renderer/api/metal/wrapper/MetalRenderPassDescriptor.h>

namespace spruce {
	class MetalCommandBuffer : public MetalObj {
		public:
			MetalCommandBuffer(void* ptr);
			MetalCommandBuffer(const MetalCommandBuffer&) = delete;
			MetalCommandBuffer(MetalCommandBuffer&&) noexcept = delete;
			~MetalCommandBuffer() override = default;

			void commit() noexcept;
			void enqueue() noexcept;
			void presentDrawable(MetalDrawable* drawable) noexcept;
			[[nodiscard]] owner<MetalRenderCommandEncoder> createRenderCommandEncoder(MetalRenderPassDescriptor& descriptor) noexcept;

			MetalCommandBuffer& operator=(const MetalCommandBuffer&) = delete;
			MetalCommandBuffer& operator=(const MetalCommandBuffer&&) noexcept = delete;
	};
}
#endif
