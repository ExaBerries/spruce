#include <backend/api/metal/MetalContext.h>

namespace spruce {
	MetalContext::MetalContext() {
		slog("create device");
		device = MTLCreateSystemDefaultDevice();
		if (device == nil) {
			serr("could not create Metal device");
			exit(EXIT_FAILURE);
		}
		commandQueue = [device newCommandQueue];
		renderEncoder = nullptr;
	}

	MetalContext::~MetalContext() {
		[device release];
		[commandQueue release];
		[depthStencilState release];
	}
}
