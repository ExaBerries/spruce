#pragma once
#include <common.h>
#include <objc/objc.h>
#include <Metal/Metal.h>
#include <MetalKit/MetalKit.h>

namespace spruce {
	class MetalContext {
		public:
			id<MTLDevice> device;
			id<MTLCommandQueue> commandQueue;
			id<MTLCommandBuffer> commandBuffer;
			id<MTLDepthStencilState> depthStencilState;
			id<MTLRenderCommandEncoder> renderEncoder;

			MetalContext();
			~MetalContext();
	};
}
