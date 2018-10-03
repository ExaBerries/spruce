#pragma once
#include <common.h>
#include <objc/objc.h>
#include <Metal/Metal.h>
#include <MetalKit/MetalKit.h>

namespace spruce {
	extern std::vector<id<MTLDevice>> devices;
	extern id<MTLDevice> physicalDevice;
	extern id<MTLCommandQueue> commandQueue;
	extern id<MTLCommandBuffer> commandBuffer;
	extern id<MTLDepthStencilState> depthStencilState;
	extern id<MTLRenderCommandEncoder> renderEncoder;

	void initDevice();
	void refreshDeviceList();
}
