#pragma once
#include <common.h>
#include <objc/objc.h>
#include <Metal/Metal.h>
#include <MetalKit/MetalKit.h>
#include <backend/mac/metal/MetalView.h>

namespace spruce {
	extern MetalView* view;
	extern std::vector<id<MTLDevice>> devices;
	extern id<MTLDevice> device;
	extern id<MTLCommandQueue> commandQueue;
	extern id<MTLCommandBuffer> commandBuffer;
	extern id<MTLDepthStencilState> depthStencilState;
	extern id<MTLRenderCommandEncoder> renderEncoder;

	void initDevice();
	void refreshDeviceList();
}
