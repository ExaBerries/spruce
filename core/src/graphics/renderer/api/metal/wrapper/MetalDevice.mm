#include <graphics/renderer/api/metal/wrapper/MetalDevice.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>
#include <backend/mac/objcpp.h>

namespace spruce {
	constexpr id<MTLDevice> castDevice(void* ptr) {
		return (__bridge id<MTLDevice>) ptr;
	}

	constexpr MTLRenderPipelineDescriptor* castRPipeDesc(void* ptr) {
		return (__bridge MTLRenderPipelineDescriptor*) ptr;
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

	owner<MetalCommandQueue> MetalDevice::createCommandQueue() {
		return new MetalCommandQueue([castDevice(ptr) newCommandQueue]);
	}

	owner<MetalBuffer> MetalDevice::createMetalBuffer(uint32 length, MetalStorageMode storageMode) {
		return new MetalBuffer([castDevice(ptr) newBufferWithLength:length options:mapMode(storageMode)]);
	}

	void MetalDevice::createTexture() {
	}

	owner<MetalLibrary> MetalDevice::createLibrary(const buffer<uint8>& data) {
		NSError* compileError = NULL;
		dispatch_data_t dispatchData = dispatch_data_create(data, data.size, nil, DISPATCH_DATA_DESTRUCTOR_DEFAULT);
		id<MTLLibrary> library = [castDevice(ptr) newLibraryWithData:dispatchData error:&compileError];
		if (!library) {
			NSLog(@"%@", compileError);
		}
		dispatch_release(dispatchData);
		return new MetalLibrary((__bridge void*) library);
	}

	owner<MetalLibrary> MetalDevice::createLibrary(const string& text) {
		NSString* objcSource = convertStr(text);
		NSError* compileError = NULL;
		id<MTLLibrary> library = [castDevice(ptr) newLibraryWithSource:objcSource options:nil error:&compileError];
		if (!library) {
			NSLog(@"%@", compileError);
		}
		return new MetalLibrary((__bridge void*) library);
	}

	owner<MetalRenderPipelineState> MetalDevice::newRenderPipelineState(const MetalRenderPipelineDescriptor& descriptor) {
		NSError* err = NULL;
		owner<MetalRenderPipelineState> state = new MetalRenderPipelineState([castDevice(ptr) newRenderPipelineStateWithDescriptor:castRPipeDesc(descriptor.ptr) error:&err]);
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
