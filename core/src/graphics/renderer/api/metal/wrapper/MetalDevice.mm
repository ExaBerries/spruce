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

	owner<MetalBuffer> MetalDevice::createBuffer(uint32 length, MetalResourceStorageMode resourceStorageMode) {
		return new MetalBuffer([castDevice(ptr) newBufferWithLength:length options:mapResourceStorageMode(resourceStorageMode)]);
	}

	owner<MetalTexture> MetalDevice::createTexture(MetalPixelFormat format, vec2i size, bool mipmap, MetalResourceStorageMode resourceStorageMode, MetalStorageMode storageMode, MetalTextureUsage usage) {
		MTLTextureDescriptor* desc = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:mapPixelFormat(format) width:size.x height:size.y mipmapped:mipmap];
		desc.resourceOptions = mapResourceStorageMode(resourceStorageMode);
		desc.storageMode = mapStorageMode(storageMode);
		desc.usage = mapTextureUsage(usage);
		return new MetalTexture([castDevice(ptr) newTextureWithDescriptor:desc]);
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

	owner<MetalDepthStencilState> MetalDevice::newDepthStencilState(MetalCompareFunction compareFunction, bool depthWrite) {
		MTLDepthStencilDescriptor* depthStencilDescriptor = [MTLDepthStencilDescriptor new];
		depthStencilDescriptor.depthCompareFunction = mapCompareFunction(compareFunction);
		depthStencilDescriptor.depthWriteEnabled = depthWrite;
		id<MTLDepthStencilState> depthStencilState = [castDevice(ptr) newDepthStencilStateWithDescriptor:depthStencilDescriptor];
		[depthStencilDescriptor release];
		return new MetalDepthStencilState(depthStencilState);
	}
}
#endif
