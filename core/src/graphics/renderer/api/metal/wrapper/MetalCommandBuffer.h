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
			~MetalCommandBuffer() = default;

			void commit();
			void enqueue();
			void presentDrawable(MetalDrawable* drawable);
			owner<MetalRenderCommandEncoder> createRenderCommandEncoder(MetalRenderPassDescriptor* descriptor);
	};
}
#endif
