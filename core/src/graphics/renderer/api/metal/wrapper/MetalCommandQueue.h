#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>
#include <graphics/renderer/api/metal/wrapper/MetalCommandBuffer.h>

namespace spruce {
	class MetalCommandQueue : public MetalObj {
		public:
			MetalCommandQueue(void* ptr);
			MetalCommandQueue(const MetalCommandQueue&) = delete;
			MetalCommandQueue(MetalCommandQueue&&) noexcept = delete;
			~MetalCommandQueue() = default;

			[[nodiscard]] owner<MetalCommandBuffer> createCommandBuffer();

			MetalCommandQueue& operator=(const MetalCommandQueue&) = delete;
			MetalCommandQueue& operator=(MetalCommandQueue&&) noexcept = delete;
	};
}
#endif
