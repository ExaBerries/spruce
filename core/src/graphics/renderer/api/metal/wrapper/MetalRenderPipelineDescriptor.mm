#include <graphics/renderer/api/metal/wrapper/MetalRenderPipelineDescriptor.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>
#include <backend/mac/objcpp.h>

namespace spruce {
	constexpr MTLRenderPipelineDescriptor* castPipelineDescriptor(void* ptr) {
		return (__bridge MTLRenderPipelineDescriptor*) ptr;
	}

	constexpr MTLVertexDescriptor* castVertexDescriptor(void* ptr) {
		return (__bridge MTLVertexDescriptor*) ptr;
	}

	constexpr id<MTLFunction> castFunction(void* ptr) {
		return (__bridge id<MTLFunction>) ptr;
	}

	MetalRenderPipelineDescriptor::MetalRenderPipelineDescriptor() : MetalObj([[MTLRenderPipelineDescriptor alloc] init]) {
	}

	MetalRenderPipelineDescriptor::~MetalRenderPipelineDescriptor() {
		[castPipelineDescriptor(ptr) release];
	}

	void MetalRenderPipelineDescriptor::setVertexFunction(const MetalFunction* function) {
		if (function != nullptr) {
			castPipelineDescriptor(ptr).vertexFunction = castFunction(function->ptr);
		} else {
			castPipelineDescriptor(ptr).vertexFunction = nil;
		}
	}

	void MetalRenderPipelineDescriptor::setFragmentFunction(const MetalFunction* function) {
		if (function != nullptr) {
			castPipelineDescriptor(ptr).fragmentFunction = castFunction(function->ptr);
		} else {
			castPipelineDescriptor(ptr).fragmentFunction = nil;
		}
	}

	void MetalRenderPipelineDescriptor::setVertexDescriptor(const MetalVertexDescriptor& descriptor) {
		castPipelineDescriptor(ptr).vertexDescriptor = castVertexDescriptor(descriptor.ptr);
	}

	void MetalRenderPipelineDescriptor::setColorAttachmentPixelFormat(uint32 index, MetalPixelFormat format) {
		castPipelineDescriptor(ptr).colorAttachments[index].pixelFormat = mapPixelFormat(format);
	}

	void MetalRenderPipelineDescriptor::setColorAttachmentBlending(uint32 index, bool blend) {
		castPipelineDescriptor(ptr).colorAttachments[index].blendingEnabled = blend;
		castPipelineDescriptor(ptr).colorAttachments[index].rgbBlendOperation = MTLBlendOperationAdd;
		castPipelineDescriptor(ptr).colorAttachments[index].alphaBlendOperation = MTLBlendOperationAdd;
		castPipelineDescriptor(ptr).colorAttachments[index].sourceRGBBlendFactor = MTLBlendFactorSourceAlpha;
		castPipelineDescriptor(ptr).colorAttachments[index].sourceAlphaBlendFactor = MTLBlendFactorSourceAlpha;
		castPipelineDescriptor(ptr).colorAttachments[index].destinationRGBBlendFactor = MTLBlendFactorOneMinusSourceAlpha;
		castPipelineDescriptor(ptr).colorAttachments[index].destinationAlphaBlendFactor = MTLBlendFactorOneMinusSourceAlpha;
	}

	void MetalRenderPipelineDescriptor::setDepthAttachmentPixelFormat(MetalPixelFormat format) {
		castPipelineDescriptor(ptr).depthAttachmentPixelFormat = mapPixelFormat(format);
	}

	void MetalRenderPipelineDescriptor::setStencilAttachmentPixelFormat(MetalPixelFormat format) {
		castPipelineDescriptor(ptr).stencilAttachmentPixelFormat = mapPixelFormat(format);
	}
}
#endif
