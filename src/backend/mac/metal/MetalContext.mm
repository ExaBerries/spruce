#include <backend/api/metal/MetalContext.h>

namespace spruce {
	MetalView* view;
	std::vector<id<MTLDevice>> devices;
	id<MTLDevice> device;
	id<MTLCommandQueue> commandQueue;
	id<MTLCommandBuffer> commandBuffer;
	id<MTLDepthStencilState> depthStencilState;
	id<MTLRenderCommandEncoder> renderEncoder;

	void initDevice() {
		device = MTLCreateSystemDefaultDevice();
		if (device == nil) {
			log("could not create Metal device");
			exit(EXIT_FAILURE);
		}
		commandQueue = [device newCommandQueue];
	}

	void refreshDeviceList() {
	}
}
