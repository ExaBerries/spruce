#include <graphics/renderer/api/metal/wrapper/MetalDevice.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>
#include <backend/mac/objcpp.h>

namespace spruce {
	constexpr id<MTLDevice> castDevice(void* ptr) {
		return (__bridge id<MTLDevice>) ptr;
	}

	MetalDevice::MetalDevice() : MetalDevice(MTLCreateSystemDefaultDevice()) {
	}

	MetalDevice::MetalDevice(void* ptr) : MetalObj(ptr) {
	}

	MetalDevice::~MetalDevice() {
		[castDevice(ptr) release];
	}

	string MetalDevice::getName() {
		return convertStr(castDevice(ptr).name);
	}

	bool MetalDevice::getLowPower() {
		return castDevice(ptr).lowPower;
	}

	bool MetalDevice::getHeadless() {
		return castDevice(ptr).headless;
	}

	bool MetalDevice::getRemoveable() {
		return castDevice(ptr).removable;
	}

	MetalCommandQueue* MetalDevice::createCommandQueue() {
		return new MetalCommandQueue([castDevice(ptr) newCommandQueue]);
	}

	MetalBuffer* MetalDevice::createMetalBuffer(uint32 length, MetalStorageMode storageMode) {
		return new MetalBuffer([castDevice(ptr) newBufferWithLength:length options:mapMode(storageMode)]);
	}

	void MetalDevice::createTexture() {

	}

	void MetalDevice::createLibrary() {

	}

	MetalRenderPipelineState* MetalDevice::newRenderPipelineState() {
		MTLRenderPipelineDescriptor* pipelineStateDescriptor = [[MTLRenderPipelineDescriptor alloc] init];
		NSError* err = nullptr;
		MetalRenderPipelineState* state = new MetalRenderPipelineState([castDevice(ptr)  newRenderPipelineStateWithDescriptor:pipelineStateDescriptor error:&err]);
		[pipelineStateDescriptor release];
		if (state->ptr == nullptr) {
			NSLog(@"error creating render pipeline state %@", err);
			return nullptr;
		}
		return state;
	}

	void MetalDevice::newComputePipelineState() {

	}
}
#endif
