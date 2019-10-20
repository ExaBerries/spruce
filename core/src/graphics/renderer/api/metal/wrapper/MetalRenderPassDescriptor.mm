#include <graphics/renderer/api/metal/wrapper/MetalRenderPassDescriptor.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>

namespace spruce {
	constexpr MTLRenderPassDescriptor* castRPDesc(void* ptr) {
		return (__bridge MTLRenderPassDescriptor*) ptr;
	}

	constexpr id<MTLTexture> castTexture(void* ptr) {
		return (__bridge id<MTLTexture>) ptr;
	}

	MetalRenderPassDescriptor::MetalRenderPassDescriptor() : MetalObj([MTLRenderPassDescriptor renderPassDescriptor]) {
	}

	void MetalRenderPassDescriptor::setColorAttachment(uint32 index, MetalTexture* texture, MetalLoadAction loadAction, MetalStoreAction storeAction, color clearColor) {
		castRPDesc(ptr).colorAttachments[index].texture = castTexture(texture->ptr);
		castRPDesc(ptr).colorAttachments[index].loadAction = mapLoadAction(loadAction);
		castRPDesc(ptr).colorAttachments[index].storeAction = mapStoreAction(storeAction);
		castRPDesc(ptr).colorAttachments[index].clearColor = MTLClearColorMake(static_cast<double>(clearColor.r), static_cast<double>(clearColor.g), static_cast<double>(clearColor.b), static_cast<double>(clearColor.a));
	}

	void MetalRenderPassDescriptor::setDepthAttachment(MetalTexture* texture, MetalLoadAction loadAction, MetalStoreAction storeAction, double clearDepth) {
		castRPDesc(ptr).depthAttachment.texture = castTexture(texture->ptr);
		castRPDesc(ptr).depthAttachment.loadAction = mapLoadAction(loadAction);
		castRPDesc(ptr).depthAttachment.storeAction = mapStoreAction(storeAction);
		castRPDesc(ptr).depthAttachment.clearDepth = clearDepth;
	}
}
#endif
